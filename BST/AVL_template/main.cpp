#include <iostream>

#include "node.h"
#include "avl.h"

using namespace std;

int main()
{
    AVLTree<int> *root = new AVLTree<int>();
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