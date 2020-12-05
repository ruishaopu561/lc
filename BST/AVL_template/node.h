#ifndef NODE_H
#define NODE_H

#include <iostream>

template <typename T>
class Node
{
public:
    int data;
    int hgt;
    Node<T> *left;
    Node<T> *right;

    Node() : left(NULL), right(NULL), hgt(0){};
    ~Node(){};
};

#endif /*NODE_H*/