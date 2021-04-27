#ifndef NODE_H
#define NODE_H

#include <string>

using namespace std;

#define DEGREE 4
#define MINCHILDRENNUM DEGREE
#define MAXCHILDRENNUM DEGREE * 2

typedef int KeyType;
typedef string DataType;

class Node
{
public:
    Node();
    ~Node();

private:
    bool isRoot;
    bool isLeaf;
    Node *parent;

    int keyNum;
    KeyType keys[MAXCHILDRENNUM];
};

class InternalNode : public Node
{
public:
    InternalNode();
    ~InternalNode();
private:
    int nodeNum;
    Node *children[MAXCHILDRENNUM];
};

class LeafNode : public Node
{
public:
    LeafNode();
    ~LeafNode();
private:
    int valueNum;
    DataType values[MAXCHILDRENNUM];
};

#endif /* NODE_H */