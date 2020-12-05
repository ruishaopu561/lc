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

template <typename T>
class RBTree
{
public:
    RBTree();
    ~RBTree();
    void insert(T data);
    bool delete_value(T data);
    Node<T> *find(T data);
    void display(ORDER order);

private:
    Node<T> *root;

    void delete_tree(Node<T> *p);

    void insert_value(Node<T> *parent, Node<T> *child, ZIGZAG zigzag, T data); // 插入节点
    void insert_case(Node<T> *p);                                              // 调整节点

    void pre_order(Node<T> *p); // 前序遍历
    void in_order(Node<T> *p);  // 中序遍历
    void pos_order(Node<T> *p); // 后序遍历

    Node<T> *find_child(Node<T> *p, T data);
    void link(Node<T> *parent, Node<T> *child, ZIGZAG zigzag);

    Node<T> *delete_find_victim(Node<T> *p);
    void delete_case(Node<T> *p);

    void rotate_right(Node<T> *p);
    void rotate_left(Node<T> *p);
};

#endif /*RBTREE_H*/