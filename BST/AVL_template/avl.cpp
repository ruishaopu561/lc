#include "avl.h"
#include <iostream>

template class AVLTree<int>;

template <typename T>
AVLTree<T>::AVLTree()
{
    root = new Node<T>();
    root->data = -1;
}

template <typename T>
AVLTree<T>::~AVLTree()
{
    delete root;
}

template <typename T>
void AVLTree<T>::insert(int x)
{
    insert_pri(root, root->right, ZAG, x);
}

template <typename T>
Node<T> *AVLTree<T>::find(int x)
{
    return find_pri(root, x);
}

template <typename T>
void AVLTree<T>::Delete(int x)
{
    delete_pri(root, root->right, ZAG, x);
}

template <typename T>
void AVLTree<T>::display(ORDER order)
{
    switch (order)
    {
    case PREORDER:
        pre_order(root->right);
        break;
    case INORDER:
        in_order(root->right);
        break;
    case POSORDER:
        pos_order(root->right);
        break;
    default:
        break;
    }
    std::cout << std::endl;
}

template <typename T>
void AVLTree<T>::insert_pri(Node<T> *parent, Node<T> *child, ZIGZAG zigzag, int x)
{
    if (!child)
    {
        child = new Node<T>();
        child->data = x;
        link(parent, child, zigzag);
        return;
    }
    if (child->data > x)
    {
        insert_pri(child, child->left, ZIG, x);
        if (height(child->left) - height(child->right) == 2)
        {
            if (child->left->data > x)
            {
                single_rotate_left(parent, child, zigzag);
            }
            else
            {
                double_rotate_left(parent, child, zigzag);
            }
        }
    }
    else if (child->data < x)
    {
        insert_pri(child, child->right, ZAG, x);
        if (height(child->right) - height(child->left) == 2)
        {
            if (child->right->data < x)
            {
                single_rotate_right(parent, child, zigzag);
            }
            else
            {
                double_rotate_right(parent, child, zigzag);
            }
        }
    }
    child->hgt = Max(height(child->left), height(child->right)) + 1;
}

template <typename T>
Node<T> *AVLTree<T>::find_pri(Node<T> *node, int x)
{
    if (!node)
    {
        return NULL;
    }

    if (node->data == x)
    {
        return node;
    }
    else if (node->data > x)
    {
        return find_pri(node->left, x);
    }
    else
    {
        return find_pri(node->right, x);
    }
}

template <typename T>
void AVLTree<T>::delete_pri(Node<T> *parent, Node<T> *child, ZIGZAG zigzag, int x)
{
    if (!child)
    {
        return;
    }
    if (child->data > x)
    {
        delete_pri(child, child->left, ZIG, x);
        if (height(child->right) - height(child->left) == 2)
        {
            if (child->right->left != NULL && (height(child->right->left) > height(child->right->right)))
            {
                double_rotate_right(parent, child, zigzag);
            }
            else
            {
                double_rotate_left(parent, child, zigzag);
            }
        }
    }
    else if (child->data < x)
    {
        delete_pri(child, child->right, ZAG, x);
        if (height(child->left) - height(child->right) == 2)
        {
            if (child->left->right != NULL && (height(child->left->right) > height(child->left->left)))
            {
                double_rotate_left(parent, child, zigzag);
            }
            else
            {
                single_rotate_left(parent, child, zigzag);
            }
        }
    }
    else
    {
        if (child->left && child->right)
        {
            Node<T> *temp = child->right;
            while (temp->left)
            {
                temp = temp->left;
            }
            child->data = temp->data;
            delete_pri(child, child->right, ZAG, temp->data);
            if (height(child->left) - height(child->right) == 2)
            {
                if (child->left->right && (height(child->left->right) > height(child->left->left)))
                {
                    double_rotate_left(parent, child, zigzag);
                }
                else
                {
                    single_rotate_left(parent, child, zigzag);
                }
            }
        }
        else
        {
            Node<T> *temp = child;
            if (!child->left)
            {
                child = child->right;
            }
            else if (!child->right)
            {
                child = child->left;
            }
            delete temp;
            temp = NULL;
        }
    }

    if (child)
    {
        child->hgt = Max(height(child->left), height(child->right)) + 1;
    }
}

template <typename T>
void AVLTree<T>::pre_order(Node<T> *node)
{
    if (!node)
    {
        return;
    }
    std::cout << node->data << " ";
    pre_order(node->left);
    pre_order(node->right);
}

template <typename T>
void AVLTree<T>::in_order(Node<T> *node)
{
    if (!node)
    {
        return;
    }
    in_order(node->left);
    std::cout << node->data << " ";
    in_order(node->right);
}

template <typename T>
void AVLTree<T>::pos_order(Node<T> *node)
{
    if (!node)
    {
        return;
    }
    pos_order(node->left);
    pos_order(node->right);
    std::cout << node->data << " ";
}

template <typename T>
int AVLTree<T>::height(Node<T> *node)
{
    if (node)
    {
        return node->hgt;
    }
    return -1;
}

template <typename T>
int AVLTree<T>::Max(int cmpa, int cmpb)
{
    return cmpa > cmpb ? cmpa : cmpb;
}

template <typename T>
void AVLTree<T>::link(Node<T> *parent, Node<T> *child, ZIGZAG zigzag)
{
    if (zigzag == ZIG)
    {
        parent->left = child;
    }
    else
    {
        parent->right = child;
    }
    parent->hgt = Max(height(parent->left), height(parent->right)) + 1;
}

template <typename T>
void AVLTree<T>::single_rotate_left(Node<T> *parent, Node<T> *child, ZIGZAG zigzag)
{
    Node<T> *k1 = child->left;
    child->left = k1->right;
    k1->right = child;

    child->hgt = Max(height(child->left), height(child->right)) + 1;
    k1->hgt = Max(height(k1->left), height(child)) + 1;

    link(parent, k1, zigzag);
}

template <typename T>
void AVLTree<T>::single_rotate_right(Node<T> *parent, Node<T> *child, ZIGZAG zigzag)
{
    Node<T> *k1 = child->right;
    child->right = k1->left;
    k1->left = child;

    child->hgt = Max(height(child->left), height(child->right)) + 1;
    k1->hgt = Max(height(child), height(k1->right)) + 1;

    link(parent, k1, zigzag);
}

template <typename T>
void AVLTree<T>::double_rotate_left(Node<T> *parent, Node<T> *child, ZIGZAG zigzag)
{
    single_rotate_right(child, child->left, ZIG);
    single_rotate_left(parent, child, zigzag);
}

template <typename T>
void AVLTree<T>::double_rotate_right(Node<T> *parent, Node<T> *child, ZIGZAG zigzag)
{
    single_rotate_left(child, child->right, ZAG);
    single_rotate_right(parent, child, zigzag);
}
