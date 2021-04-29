#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

using namespace std;

#define DEGREE 2
#define MINCHILDRENNUM DEGREE
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
    KeyType keys[MAXCHILDRENNUM];

    Node();
    ~Node();

    bool getIsRoot();
    void setIsRoot(bool);
    bool getIsLeaf();
    void setIsLeaf(bool);
    int getKeyNum();
    int getKeyIndex(KeyType);

    void insertKey(int, KeyType);
    void deleteKey(int);
    void setKey(int, KeyType);
    KeyType getKey(int);

    // 如有分裂，返回新节点
    virtual Node *insert(KeyType, DataType) = 0;
    virtual void remove(KeyType) = 0;
    virtual void set(KeyType, DataType) = 0;
    virtual void iterate() = 0;

private:
    bool isRoot;
    bool isLeaf;
    int keyNum;

    virtual Node *split() = 0;
};

class InternalNode : public Node
{
public:
    InternalNode();
    ~InternalNode();

    void insertNode(int, Node *);
    void deleteNode(int);
    void setNode(int, Node *);
    Node *getNode(int);

    virtual Node *insert(KeyType, DataType);
    virtual void remove(KeyType);
    virtual void set(KeyType, DataType);
    virtual void iterate();

private:
    int nodeNum;
    Node *children[MAXCHILDRENNUM];

    virtual Node *split();
};

class LeafNode : public Node
{
public:
    LeafNode();
    ~LeafNode();

    void insertValue(int, DataType);
    void deleteValue(int);
    void setValue(int, DataType);
    DataType getValue(int);

    virtual Node *insert(KeyType, DataType);
    virtual void remove(KeyType);
    virtual void set(KeyType, DataType);
    virtual void iterate();

private:
    int valueNum;
    DataType values[MAXCHILDRENNUM];

    virtual Node *split();
};

#endif /* NODE_H */