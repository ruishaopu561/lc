#ifndef BPTREE_H
#define BPTREE_H

#include "Error.h"
#include "List.h"
#include "Node.h"

class BPTree
{
public:
    BPTree();
    ~BPTree();

    ERROR insert(KeyType, DataType);
    ERROR remove(KeyType);
    ERROR set(KeyType, DataType);
    ERROR get(KeyType, DataType &);
    void iterate();
    void printTree();

private:
    Node *root;
    void *head;
};

#endif /* BPTREE_H */
