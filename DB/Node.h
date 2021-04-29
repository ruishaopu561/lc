#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

#include "List.h"

using namespace std;

#define DEGREE 2
#define MINnodesNUM DEGREE
#define MAXCHILDRENNUM DEGREE * 2

#define KEYNULL 0
#define DATANULL ""

typedef int KeyType;
typedef string DataType;

class Node
{
public:
    Node *prev;
    Node *next;
    List<KeyType> *keys;

    Node();
    ~Node();

    bool getIsRoot();
    void setIsRoot(bool);
    bool getIsLeaf();
    void setIsLeaf(bool);

    // 定位 key 在当前 node 中的 keys 里的位置
    int getKeyIndex(KeyType);

    // 如有分裂，返回新节点
    virtual Node *insert(KeyType, DataType) = 0;
    virtual Node *remove(KeyType) = 0;
    virtual void set(KeyType, DataType) = 0;
    virtual void iterate() = 0;

private:
    bool isRoot;
    bool isLeaf;

    virtual Node *split() = 0;
    virtual Node *merge(Node *, Node *) = 0;
};

class InternalNode : public Node
{
public:
    InternalNode();
    ~InternalNode();

    void addNode(int, KeyType, Node *);
    void deleteNode(int);

    virtual Node *insert(KeyType, DataType);
    virtual Node *remove(KeyType);
    virtual void set(KeyType, DataType);
    virtual void iterate();

private:
    List<Node *> *nodes;

    virtual Node *split();
    virtual Node *merge(Node *, Node *);
};

class LeafNode : public Node
{
public:
    LeafNode();
    ~LeafNode();

    void addValue(int, KeyType, DataType);
    void deleteValue(int);

    virtual Node *insert(KeyType, DataType);
    virtual Node *remove(KeyType);
    virtual void set(KeyType, DataType);
    virtual void iterate();

private:
    List<DataType> *values;

    virtual Node *split();
    virtual Node *merge(Node *, Node *);
};

#endif /* NODE_H */