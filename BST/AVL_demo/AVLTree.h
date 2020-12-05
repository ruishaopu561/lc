#ifndef AVLTREE_H
#define AVLTREE_H

#include "TreeNode.h"

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

class AVLTree
{
public:
    AVLTree();
    ~AVLTree();
    void insert(int x);        // 插入
    TreeNode *find(int x);     // 查找
    void Delete(int x);        // 删除
    void display(ORDER order); // 遍历

private:
    TreeNode *root;

    void insert_pri(TreeNode *parent, TreeNode *child, ZIGZAG zigzag, int x); // 递归插入
    TreeNode *find_pri(TreeNode *node, int x);                                // 递归查找
    void delete_pri(TreeNode *parent, TreeNode *child, ZIGZAG zigzag, int x); // 递归删除

    void pre_order(TreeNode *node); // 前序遍历
    void in_order(TreeNode *node);  // 中序遍历
    void pos_order(TreeNode *node); // 后序遍历

    int height(TreeNode *node);                                  // 节点高度
    int Max(int cmpa, int cmpb);                                 // 求最大值
    void link(TreeNode *parent, TreeNode *child, ZIGZAG zigzag); // 旋转后连接父子节点；

    void single_rotate_left(TreeNode *parent, TreeNode *child, ZIGZAG zigzag);  // 左左旋转
    void single_rotate_right(TreeNode *parent, TreeNode *child, ZIGZAG zigzag); // 右右旋转
    void double_rotate_left(TreeNode *parent, TreeNode *child, ZIGZAG zigzag);  // 左右旋转
    void double_rotate_right(TreeNode *parent, TreeNode *child, ZIGZAG zigzag); // 右左旋转
};

#endif /*AVLTREE_H*/