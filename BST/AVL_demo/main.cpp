#include <iostream>

#include "TreeNode.h"
#include "AVLTree.h"

using namespace std;

int main()
{
    AVLTree *root = new AVLTree();
    root->insert(1);
    root->display(PREORDER);
    root->insert(2);
    root->display(PREORDER);
    root->insert(3);
    root->display(PREORDER);
    root->insert(4);
    root->display(PREORDER);
    root->insert(5);
    root->display(PREORDER);
    root->insert(6);
    root->display(PREORDER);
    root->insert(7);
    root->display(PREORDER);

    return 0;
}