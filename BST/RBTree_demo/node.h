#ifndef NODE_H
#define NODE_H

#include <iostream>

#define RED 0
#define BLACK 1

enum ZIGZAG
{
    ZIG,
    ZAG
};

class Node
{
public:
    int value;
    bool color;
    Node *left, *right, *parent;

    Node() : value(-1), color(RED), left(NULL), right(NULL), parent(NULL){};
    Node(int v) : value(v), color(RED), left(NULL), right(NULL), parent(NULL){};
    Node(int v, Node *l, Node *r, Node *p) : value(v), color(RED), left(l), right(r), parent(p){};

    Node *grandparent()
    {
        return parent ? parent->parent : NULL;
    }

    std::string print_color()
    {
        return (color == RED) ? "RED" : "BLACK";
    }

    Node *uncle()
    {
        if (grandparent() == NULL)
        {
            return NULL;
        }

        return (parent->if_left_child() == ZIG) ? grandparent()->right : grandparent()->left;
    }

    Node *sibling()
    {
        return (if_left_child() == ZIG) ? parent->right : parent->left;
    }

    ZIGZAG if_left_child() // 是不是父节点的左节点
    {
        return (parent && parent->left == this) ? ZIG : ZAG;
    }
};

#endif /*NODE_H*/