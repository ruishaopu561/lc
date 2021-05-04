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
    keys = new List<KeyType>(MAXCHILDRENNUM);
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

int Node::getKeyIndex(KeyType key)
{
    int index = 0, i = 0, size = keys->getSize();
    for (; i < size; i++)
    {
        KeyType k = keys->getValue(i);
        if (key < k)
        {
            index = (i - 1 < 0) ? 0 : i - 1;
            break;
        }
        else if (key == k)
        {
            index = i;
            break;
        }
    }
    index = (i == size) ? i - 1 : index;
    return index;
}

/*
 * Internal Node
 */
InternalNode::InternalNode()
{
    setIsLeaf(false);
    nodes = new List<Node *>(MAXCHILDRENNUM);
}

InternalNode::~InternalNode()
{
    int index = nodes->getSize();
    for (int i = 0; i < index; i++)
    {
        nodes->setValue(i, NULL);
    }
    delete nodes;
}

void InternalNode::addNode(int index, KeyType key, Node *child)
{
    keys->insertValue(index, key);
    nodes->insertValue(index, child);
}

void InternalNode::deleteNode(int index)
{
    keys->deleteValue(index);
    nodes->deleteValue(index);
}

Node *InternalNode::insert(KeyType key, DataType value)
{
    Node *child = NULL;
    int index = getKeyIndex(key), size = nodes->getSize();
    index = (index < size) ? index : size - 1;

    child = (nodes->getValue(index))->insert(key, value);
    // 插入之后 key 有可能变化，修改一下
    keys->setValue(index, (nodes->getValue(index))->keys->getValue(0));

    if (child == NULL)
    {
        return NULL;
    }

    keys->setValue(index, nodes->getValue(index)->keys->getValue(0));
    if (size < MAXCHILDRENNUM)
    {
        addNode(index + 1, child->keys->getValue(0), child);
        return NULL;
    }

    // 分裂
    InternalNode *sibling = (InternalNode *)split();
    // 插值
    if (index + 1 < DEGREE)
    {
        addNode(index + 1, child->keys->getValue(0), child);
    }
    else
    {
        sibling->addNode(index + 1 - DEGREE, child->keys->getValue(0), child);
    }
    return sibling;
}

Node *InternalNode::remove(KeyType key)
{
    int index = getKeyIndex(key);
    Node *sibling = (nodes->getValue(index))->remove(key);

    if (!sibling)
    {
        keys->setValue(index, (nodes->getValue(index)->keys->getValue(0)));
        return NULL;
    }

    // 合并了左节点
    if (index > 0 && sibling->keys->getValue(0) == nodes->getValue(index - 1)->keys->getValue(0))
    {
        deleteNode(index);
    }
    else
    {
        keys->setValue(index, (nodes->getValue(index)->keys->getValue(0)));
        deleteNode(index + 1);
    }

    // 检查合并
    if (nodes->getSize() >= DEGREE)
    {
        return NULL;
    }
    // to be root
    if (!prev && !next)
    {
        // cout << sibling->keys->getSize() << endl;
        sibling->iterate();
        return sibling;
    }

    InternalNode *p = (InternalNode *)prev, *n = (InternalNode *)next;
    if (p)
    {
        int size = p->keys->getSize();
        if (size > DEGREE)
        {
            addNode(0, p->keys->getValue(size - 1), p->nodes->getValue(size - 1));
            p->deleteNode(size - 1);
            return NULL;
        }
        else
        {
            return merge(p, this);
        }
    }
    else
    {
        if (n->keys->getSize() > DEGREE)
        {
            addNode(nodes->getSize(), n->keys->getValue(0), n->nodes->getValue(0));
            n->deleteNode(0);
            return NULL;
        }
        else
        {
            return merge(this, n);
        }
    }
}

bool InternalNode::set(KeyType key, DataType value)
{
    int index = getKeyIndex(key);
    return (nodes->getValue(index))->set(key, value);
}

bool InternalNode::get(KeyType key, DataType &return_val)
{
    int index = getKeyIndex(key);
    return (nodes->getValue(index))->get(key, return_val);
}

bool InternalNode::find(KeyType key)
{
    int index = getKeyIndex(key);
    return (nodes->getValue(index))->find(key);
}

void InternalNode::iterate()
{
    int size = nodes->getSize();
    for (int i = 0; i < size; i++)
    {
        cout << keys->getValue(i) << ": ";
        nodes->getValue(i)->iterate();
    }
    cout << endl;
}

Node *InternalNode::getHead()
{
    Node *child = nodes->getValue(0);
    return child->getIsLeaf() ? child : child->getHead();
}

Node *InternalNode::split()
{
    int start = DEGREE;
    InternalNode *sibling = new InternalNode();
    for (int i = start; i < MAXCHILDRENNUM; i++)
    {
        sibling->addNode(i - start, keys->getValue(start), nodes->getValue(start));
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

Node *InternalNode::merge(Node *l, Node *r)
{
    InternalNode *left = (InternalNode *)l, *right = (InternalNode *)r;
    int lsize = left->keys->getSize(), rsize = right->keys->getSize();
    for (int i = 0; i < rsize; i++)
    {
        left->addNode(lsize + i, right->keys->getValue(0), right->nodes->getValue(0));
        right->deleteNode(0);
    }

    // 双链表删除节点
    left->next = right->next;
    if (right->next)
    {
        right->next->prev = left;
    }
    delete right;
    right = NULL;

    return left;
}

/*
 * Leaf Node
 */
LeafNode::LeafNode()
{
    setIsLeaf(true);
    values = new List<DataType>(MAXCHILDRENNUM);
}

LeafNode::~LeafNode() {}

void LeafNode::addValue(int index, KeyType key, DataType value)
{
    keys->insertValue(index, key);
    values->insertValue(index, value);
}

void LeafNode::deleteValue(int index)
{
    keys->deleteValue(index);
    values->deleteValue(index);
}

Node *LeafNode::insert(KeyType key, DataType value)
{
    int index = keys->getValueIndex(key);

    if (values->getSize() < MAXCHILDRENNUM)
    {
        addValue(index, key, value);
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

Node *LeafNode::remove(KeyType key)
{
    int size = values->getSize();
    for (int i = 0; i < size; i++)
    {
        if (keys->getValue(i) == key)
        {
            deleteValue(i);
            // 检查合并
            if (values->getSize() >= DEGREE || (!prev && !next))
            {
                return NULL;
            }

            LeafNode *p = (LeafNode *)prev, *n = (LeafNode *)next;
            if (p)
            {
                int size = p->keys->getSize();
                if (size > DEGREE)
                {
                    addValue(0, p->keys->getValue(size - 1), p->values->getValue(size - 1));
                    p->deleteValue(size - 1);
                    return NULL;
                }
                else
                {
                    return merge(p, this);
                }
            }
            else
            {
                int size = n->keys->getSize();
                if (size > DEGREE)
                {
                    addValue(values->getSize(), n->keys->getValue(0), n->values->getValue(0));
                    n->deleteValue(0);
                    return NULL;
                }
                else
                {
                    return merge(this, n);
                }
            }
        }
    }
    return NULL;
}

bool LeafNode::set(KeyType key, DataType value)
{
    int size = values->getSize();
    for (int i = 0; i < size; i++)
    {
        if (keys->getValue(i) == key)
        {
            values->setValue(i, value);
            return true;
        }
    }
    return false;
}

bool LeafNode::get(KeyType key, DataType &return_val)
{
    int size = values->getSize();
    for (int i = 0; i < size; i++)
    {
        if (keys->getValue(i) == key)
        {
            return_val = values->getValue(i);
            return true;
        }
    }
    return false;
}

bool LeafNode::find(KeyType key)
{
    int size = values->getSize();
    for (int i = 0; i < size; i++)
    {
        if (keys->getValue(i) == key)
        {
            return true;
        }
    }
    return false;
}

void LeafNode::iterate()
{
    int size = values->getSize();
    for (int i = 0; i < size; i++)
    {
        cout << keys->getValue(i) << ":" << values->getValue(i) << "; ";
    }
    cout << endl;
}

Node *LeafNode::getHead()
{
    return this;
}

Node *LeafNode::split()
{
    int start = DEGREE;
    LeafNode *sibling = new LeafNode();
    for (int i = start; i < MAXCHILDRENNUM; i++)
    {
        sibling->addValue(i - start, keys->getValue(start), values->getValue(start));
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

Node *LeafNode::merge(Node *l, Node *r)
{
    LeafNode *left = (LeafNode *)l, *right = (LeafNode *)r;
    int lsize = left->keys->getSize(), rsize = right->keys->getSize();
    for (int i = 0; i < rsize; i++)
    {
        left->addValue(lsize + i, right->keys->getValue(0), right->values->getValue(0));
        right->deleteValue(0);
    }

    // 双链表删除节点
    left->next = right->next;
    if (right->next)
    {
        right->next->prev = left;
    }
    delete right;
    right = NULL;

    return left;
}