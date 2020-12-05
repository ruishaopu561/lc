#ifndef RBTREE_H
#define RBTREE_H

/*
 * reference: https://www.jianshu.com/p/e136ec79235c
 * 性质1. 节点是红色或黑色。
 * 性质2. 根是黑色。
 * 性质3. 所有叶子都是黑色（叶子是NULL）。
 * 性质4. 每个红色节点必须有两个黑色的子节点。(从每个叶子到根的所有路径上不能有两个连续的红色节点。)
 * 性质5. 从任一节点到其每个叶子的所有简单路径都包含相同数目的黑色节点。
 */

#include "node.h"

enum ORDER
{
    PREORDER,
    INORDER,
    POSORDER
};

class RBTree
{
public:
    RBTree();
    ~RBTree();
    void insert(int data);
    bool delete_value(int data);
    Node *find(int data);
    void display(ORDER order);

private:
    Node *root;

    void delete_tree(Node *p);

    void insert_value(Node *parent, Node *child, ZIGZAG zigzag, int data); // 插入节点
    void insert_case(Node *p);                                             // 调整节点

    void pre_order(Node *p); // 前序遍历
    void in_order(Node *p);  // 中序遍历
    void pos_order(Node *p); // 后序遍历

    Node *find_child(Node *p, int data);
    void link(Node *parent, Node *child, ZIGZAG zigzag);

    Node *delete_find_victim(Node *p);
    void delete_case(Node *p);

    void rotate_right(Node *p);
    void rotate_left(Node *p);
};

#endif /*RBTREE_H*/