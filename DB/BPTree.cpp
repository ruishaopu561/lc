#include "BPTree.h"

BPTree::BPTree()
{
    root = NULL;
    head = NULL;
}

BPTree::~BPTree()
{
    delete root;
    root = NULL;
    head = NULL;
}

ERROR BPTree::insert(KeyType key, DataType value)
{
    if (root == NULL)
    {
        root = new LeafNode();
        head = (void *)root;
    }

    if (root->find(key))
    {
        return EXIST;
    }

    Node *child = root->insert(key, value);
    if (child)
    {
        root->setIsRoot(false);
        InternalNode *newRoot = new InternalNode();
        newRoot->setIsRoot(true);

        int key1 = root->keys->getValue(0), key2 = child->keys->getValue(0);
        if (key1 < key2)
        {
            newRoot->addNode(0, key1, root);
            newRoot->addNode(1, key2, child);
        }
        else
        {
            newRoot->addNode(0, key2, child);
            newRoot->addNode(1, key1, root);
        }

        root = newRoot;
        head = (void *)root->getHead();
    }

    return OK;
}

ERROR BPTree::remove(KeyType key)
{
    if (!root || !root->find(key))
    {
        return NONEXIST;
    }

    Node *child = root->remove(key);
    if (child)
    {
        root = child;
        root->setIsRoot(true);
        head = (void *)root->getHead();
    }
    return OK;
}

ERROR BPTree::set(KeyType key, DataType value)
{
    if (!root || !root->find(key))
    {
        return NONEXIST;
    }

    if (root->set(key, value))
    {
        return OK;
    }
    else
    {
        return NONEXIST;
    }
}

ERROR BPTree::get(KeyType key, DataType &return_val)
{
    if (root && root->get(key, return_val))
    {
        return OK;
    }
    else
    {
        return NONEXIST;
    }
}

void BPTree::iterate()
{
    if (!head)
    {
        return;
    }

    Node *p = (Node *)head;
    while (p)
    {
        p->iterate();
        p = p->next;
    }
}

void BPTree::printTree()
{
    if (!root)
    {
        return;
    }

    root->iterate();
}
