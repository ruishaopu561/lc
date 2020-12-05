#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>

class TreeNode
{
public:
    int data;
    int hgt;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : left(NULL), right(NULL), hgt(0){};
    ~TreeNode(){};
};

#endif /*TREENODE_H*/