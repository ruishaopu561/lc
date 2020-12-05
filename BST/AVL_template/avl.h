#ifndef AVLTREE_H
#define AVLTREE_H

#include "node.h"

enum ZIGZAG
{
    ZIG,
    ZAG
};

enum ORDER
{
    PREORDER,
    INORDER,
    POSORDER
};

template <typename T>
class AVLTree
{
public:
    AVLTree();
    ~AVLTree();
    void insert(int x);        // 插入
    Node<T> *find(int x);     // 查找
    void Delete(int x);        // 删除
    void display(ORDER order); // 遍历

private:
    Node<T> *root;

    void insert_pri(Node<T> *parent, Node<T> *child, ZIGZAG zigzag, int x); // 递归插入
    Node<T> *find_pri(Node<T> *node, int x);                                // 递归查找
    void delete_pri(Node<T> *parent, Node<T> *child, ZIGZAG zigzag, int x); // 递归删除

    void pre_order(Node<T> *node); // 前序遍历
    void in_order(Node<T> *node);  // 中序遍历
    void pos_order(Node<T> *node); // 后序遍历

    int height(Node<T> *node);                                  // 节点高度
    int Max(int cmpa, int cmpb);                                 // 求最大值
    void link(Node<T> *parent, Node<T> *child, ZIGZAG zigzag); // 旋转后连接父子节点；

    void single_rotate_left(Node<T> *parent, Node<T> *child, ZIGZAG zigzag);  // 左左旋转
    void single_rotate_right(Node<T> *parent, Node<T> *child, ZIGZAG zigzag); // 右右旋转
    void double_rotate_left(Node<T> *parent, Node<T> *child, ZIGZAG zigzag);  // 左右旋转
    void double_rotate_right(Node<T> *parent, Node<T> *child, ZIGZAG zigzag); // 右左旋转
};

#endif /*AVLTREE_H*/