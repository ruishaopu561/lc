#include "Node.h"

/*
 * Super class: Node
 */
Node::Node()
{
    isRoot = false;
    isLeaf = false;
    prev = NULL;
    next = NULL;

    keyNum = 0;
    for (int i = 0; i < MAXCHILDRENNUM; i++)
    {
        keys[i] == KEYNULL;
    }
}

Node::~Node()
{
    prev = NULL;
    next = NULL;
}

bool Node::getIsRoot()
{
    return isRoot;
}

void Node::setIsRoot(bool root)
{
    isRoot = root;
}

bool Node::getIsLeaf()
{
    return isLeaf;
}

void Node::setIsLeaf(bool leaf)
{
    isLeaf = leaf;
}

int Node::getKeyNum()
{
    return keyNum;
}

// 返回插入的索引
int Node::getKeyIndex(KeyType key)
{
    for (int i = 0; i < keyNum; i++)
    {
        if (key < keys[i])
        {
            return i;
        }
    }

    return keyNum;
}

void Node::insertKey(int index, KeyType key)
{
    if (index >= keyNum)
    {
        keys[keyNum++] = key;
    }
    else
    {
        int j = keyNum;
        while (j > index)
        {
            keys[j] = keys[j - 1];
            j--;
        }
        keys[index] = key;
    }
}

void Node::deleteKey(int index)
{
    if (index < 0 || index >= keyNum)
    {
        return;
    }
    int i = index;
    for (; i + 1 < keyNum; i++)
    {
        keys[i] = keys[i + 1];
    }
    if (i + 1 == keyNum)
    {
        keys[i] = KEYNULL;
    }
    keyNum--;
}

void Node::setKey(int index, KeyType key)
{
    keys[index] = key;
}

KeyType Node::getKey(int index)
{
    if(index < 0 || index>=keyNum){return KEYNULL;}
    return keys[index];
}

/*
 * Internal Node
 */
InternalNode::InternalNode()
{
    setIsLeaf(false);

    nodeNum = 0;
    for (int i = 0; i < MAXCHILDRENNUM; i++)
    {
        children[i] = NULL;
    }
}

InternalNode::~InternalNode()
{
    int index = (nodeNum < MAXCHILDRENNUM) ? nodeNum : MAXCHILDRENNUM;
    for (int i = 0; i < index; i++)
    {
        delete children[i];
        children[i] = NULL;
    }
}

void InternalNode::insertNode(int index, Node *child)
{
    if (index >= nodeNum)
    {
        children[index] = child;
    }
    else
    {
        int i = nodeNum;
        while (i > index)
        {
            children[i] = children[i - 1];
            i--;
        }
        children[index] = child;
    }
    nodeNum++;
}

void InternalNode::deleteNode(int index)
{
    if (index < 0 || index >= nodeNum)
    {
        return;
    }
    int i = index;
    for (; i + 1 < nodeNum; i++)
    {
        children[i] = children[i + 1];
    }
    if (i + 1 == nodeNum)
    {
        children[i] = NULL;
    }
    nodeNum--;
}

void InternalNode::setNode(int index, Node *node)
{
    if(index<0 || index>=nodeNum){return;}
    children[index] = node;
}

Node *InternalNode::getNode(int index)
{
    if(index<0 || index>=nodeNum){return NULL;}
    return children[index];
}

Node *InternalNode::insert(KeyType key, DataType value)
{
    Node *child = NULL;
    int index = getKeyIndex(key);
    index = (index < nodeNum) ? index : nodeNum - 1;

    child = children[index]->insert(key, value);
    if (child == NULL)
    {
        return NULL;
    }
    else
    {
        setKey(index, children[index]->keys[0]);
        if (nodeNum < MAXCHILDRENNUM)
        {
            insertKey(index + 1, child->keys[0]);
            insertNode(index + 1, child);
            return NULL;
        }

        // 分裂
        InternalNode *sibling = (InternalNode *)split();
        // 插值
        if (index + 1 < DEGREE)
        {
            insertKey(index + 1, child->keys[0]);
            insertNode(index + 1, child);
        }
        else
        {
            sibling->insertKey(index + 1 - DEGREE, child->keys[0]);
            sibling->insertNode(index + 1 - DEGREE, child);
        }
        return sibling;
    }
}

void InternalNode::remove(KeyType)
{

}

void InternalNode::set(KeyType key, DataType value)
{
    // 这块找 index 能复用吗？
    int index = 0, i=0;
    for (; i < nodeNum; i++)
    {
        if (key < getKey(i))
        {
            index = (i-1<0)?0:i-1;
            break;
        }else if(key == getKey(i))
        {
            index = i;
            break;
        }
    }
    index = (i==nodeNum)? i-1:index;

    children[index]->set(key, value);
}

void InternalNode::iterate()
{
    for (int i=0; i<nodeNum; i++)
    {
        cout << keys[i] << ": ";
        children[i]->iterate();
    }
    cout << endl;
}

Node *InternalNode::split()
{
    int start = DEGREE;
    InternalNode *sibling = new InternalNode();
    for (int i = start; i < MAXCHILDRENNUM; i++)
    {
        sibling->insertKey(i - start, keys[start]);
        sibling->insertNode(i - start, children[start]);
        deleteKey(start);
        deleteNode(start);
    }

    // 双链表插节点
    if (next)
    {
        next->prev = sibling;
        sibling->next = next;
    }
    next = sibling;
    sibling->prev = this;

    return sibling;
}


/*
 * Leaf Node
 */
LeafNode::LeafNode()
{
    setIsLeaf(true);

    valueNum = 0;
    for (int i = 0; i < MAXCHILDRENNUM; i++)
    {
        values[i] = DATANULL;
    }
}

LeafNode::~LeafNode() {}

void LeafNode::insertValue(int index, DataType value)
{
    if (index >= valueNum)
    {
        values[index] = value;
    }
    else
    {
        int i = valueNum;
        while (i > index)
        {
            values[i] = values[i - 1];
            i--;
        }
        values[index] = value;
    }
    valueNum++;
}

void LeafNode::deleteValue(int index)
{
    if (index < 0 || index >= valueNum)
    {
        return;
    }
    int i = index;
    for (; i + 1 < valueNum; i++)
    {
        values[i] = values[i + 1];
    }

    if (i + 1 == valueNum)
    {
        values[i] = DATANULL;
    }
    valueNum--;
}

void LeafNode::setValue(int index, DataType value)
{
    if(index<0 || index>=valueNum){return;}
    values[index] = value;
}

DataType LeafNode::getValue(int index)
{
    if(index<0 || index>=valueNum){return DATANULL;}
    return values[index];
}

Node *LeafNode::insert(KeyType key, DataType value)
{
    int index = getKeyIndex(key);

    if (valueNum < MAXCHILDRENNUM)
    {
        insertKey(index, key);
        insertValue(index, value);
        return NULL;
    }

    // 分裂
    LeafNode *sibling = (LeafNode *)split();
    // 插值
    if (index < DEGREE)
    {
        insert(key, value);
    }
    else
    {
        sibling->insert(key, value);
    }
    return sibling;
}

void LeafNode::remove(KeyType key)
{

}

void LeafNode::set(KeyType key, DataType value)
{
    for(int i=0; i<valueNum; i++)
    {
        cout << getKey(i) << " " << key << endl;
        if(getKey(i) == key){
            values[i] = value;
            return;
        }
    }
}

void LeafNode::iterate()
{
    for (int i = 0; i < valueNum; i++)
    {
        cout << keys[i] << ":" << values[i] << "; ";
    }
    cout << endl;
}

Node *LeafNode::split()
{
    int start = DEGREE;
    LeafNode *sibling = new LeafNode();
    for (int i = start; i < MAXCHILDRENNUM; i++)
    {
        sibling->insertKey(i - start, keys[start]);
        sibling->insertValue(i - start, values[start]);
        deleteKey(start);
        deleteValue(start);
    }

    // 双链表插节点
    if (next)
    {
        next->prev = sibling;
        sibling->next = next;
    }
    next = sibling;
    sibling->prev = this;

    return sibling;
}
