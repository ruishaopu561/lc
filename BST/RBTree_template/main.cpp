#include <iostream>

#include "node.h"
#include "rbTree.h"

using namespace std;

int main()
{
    RBTree<int> *root = new RBTree<int>();
    root->insert(1);
    // root->display(PREORDER);
    root->insert(2);
    // root->display(PREORDER);
    root->insert(3);
    // root->display(PREORDER);
    root->insert(4);
    // root->display(PREORDER);
    root->insert(5);
    // root->display(PREORDER);
    root->insert(6);
    // root->display(PREORDER);
    root->insert(7);
    // root->display(PREORDER);
    root->insert(8);
    // root->display(PREORDER);
    root->delete_value(5);
    // root->display(PREORDER);
    root->delete_value(2);
    root->insert(43);
    root->insert(65);
    root->insert(11);
    root->insert(23);
    root->insert(34);
    root->insert(40);
    root->insert(9);
    root->insert(10);
    root->insert(40);
    root->insert(41);
    root->display(PREORDER);
    // Node*node = root->find(3);
    // std::cout << node->print_color() << std::endl;

    return 0;
}