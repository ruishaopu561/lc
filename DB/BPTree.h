#ifndef BPTREE_H
#define BPTREE_H

#include "List.h"
#include "Node.h"

class BPTree
{
public:
    BPTree();
    ~BPTree();

    bool insert(KeyType, DataType);
    bool remove(KeyType);
    bool set(KeyType, DataType);
    bool get(KeyType, DataType &);
    void iterate();
    void printTree();

private:
    Node *root;
    void *head;
};

#endif /* BPTREE_H */
