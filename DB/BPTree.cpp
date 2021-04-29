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

bool BPTree::insert(KeyType key, DataType value)
{
    if (root == NULL)
    {
        root = new LeafNode();
        head = (void *)root;
    }
    Node *child = root->insert(key, value);
    if(child){
        root->setIsRoot(false);
        InternalNode*newRoot = new InternalNode();
        newRoot->setIsRoot(true);

        int key1 = root->keys[0], key2 = child->keys[0];
        if(key1 < key2){
            newRoot->insertKey(0, key1);
            newRoot->insertNode(0, root);
            newRoot->insertKey(1, key2);
            newRoot->insertNode(1,child);
        }else{
            newRoot->insertKey(0, key1);
            newRoot->insertNode(0, root);
            newRoot->insertKey(1, key2);
            newRoot->insertNode(1,child);
        }

        root = newRoot;
    }

    return true;
}

bool BPTree::remove(KeyType key)
{
    return true;
}

bool BPTree::set(KeyType key, DataType value)
{
    if(!root){
        return false;
    }

    root->set(key, value);
    return true;
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
