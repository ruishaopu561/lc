#include "BPTree.h"

BPTree::BPTree()
{
    root = NULL;
}

BPTree::~BPTree()
{
    delete root;
    root = NULL;
}