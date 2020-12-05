#include "rbTree.h"

template class RBTree<int>;

template <typename T>
RBTree<T>::RBTree()
{
    root = NULL;
}

template <typename T>
RBTree<T>::~RBTree()
{
    if (root)
    {
        delete_tree(root);
    }
}

template <typename T>
void RBTree<T>::delete_tree(Node<T> *p)
{
    if (!p)
    {
        return;
    }

    delete_tree(p->left);
    delete_tree(p->right);
    delete p;
}

template <typename T>
void RBTree<T>::display(ORDER order)
{
    switch (order)
    {
    case PREORDER:
        pre_order(root);
        break;
    case INORDER:
        in_order(root);
        break;
    case POSORDER:
        pos_order(root);
        break;
    default:
        break;
    }
    std::cout << std::endl;
}

template <typename T>
void RBTree<T>::pre_order(Node<T> *p)
{
    if (!p)
    {
        return;
    }

    std::cout << p->value << "-";
    std::cout << p->print_color() << "  ";

    if (p->left)
    {
        pre_order(p->left);
    }

    if (p->right)
    {
        pre_order(p->right);
    }
}

template <typename T>
void RBTree<T>::in_order(Node<T> *p)
{
    if (!p)
    {
        return;
    }

    if (p->left)
    {
        in_order(p->left);
    }

    std::cout << p->value << "-";
    std::cout << p->print_color() << "  ";

    if (p->right)
    {
        in_order(p->right);
    }
}

template <typename T>
void RBTree<T>::pos_order(Node<T> *p)
{
    if (!p)
    {
        return;
    }

    if (p->left)
    {
        pos_order(p->left);
    }

    if (p->right)
    {
        pos_order(p->right);
    }
    std::cout << p->value << "-";
    std::cout << p->print_color() << "  ";
}

template <typename T>
Node<T> *RBTree<T>::find(T data)
{
    return find_child(root, data);
}

template <typename T>
Node<T> *RBTree<T>::find_child(Node<T> *p, T data)
{
    if (!p)
    {
        return NULL;
    }

    if (p->value == data)
    {
        return p;
    }
    else if (p->value > data)
    {
        return find_child(p->left, data);
    }
    else
    {
        return find_child(p->right, data);
    }
}

template <typename T>
void RBTree<T>::insert(T data)
{
    insert_value(NULL, root, ZIG, data);
}

template <typename T>
void RBTree<T>::insert_value(Node<T> *parent, Node<T> *child, ZIGZAG zigzag, T data)
{
    if (!child)
    {
        child = new Node<T>(data);
        link(parent, child, zigzag);
        insert_case(child);
    }
    else if (child->value > data)
    {
        insert_value(child, child->left, ZIG, data);
    }
    else if (child->value < data)
    {
        insert_value(child, child->right, ZAG, data);
    }
}

template <typename T>
void RBTree<T>::insert_case(Node<T> *p)
{
    if (p->parent == NULL)
    {
        p->color = BLACK;
        // root = p;
        return;
    }
    else if (p->parent->color == BLACK)
    {
        return;
    }
    // 仅在父节点为红色才进来，如果祖节点不存在，那么父节点就是root，root必为黑色，不会进去
    // 也就是说既然进来了，那么祖节点一定是存在的；
    if (p->uncle() && p->uncle()->color == RED)
    {
        p->parent->color = p->uncle()->color = BLACK;
        p->grandparent()->color = RED;
        insert_case(p->grandparent());
    }
    else
    {
        if (p->if_left_child() == ZAG && p->parent->if_left_child() == ZIG)
        {
            rotate_left(p);
            rotate_right(p);
            p->color = BLACK;
            p->left->color = p->right->color = RED;
        }
        else if (p->if_left_child() == ZIG && p->parent->if_left_child() == ZAG)
        {
            rotate_right(p);
            rotate_left(p);
            p->color = BLACK;
            p->left->color = p->right->color = RED;
        }
        else if (p->if_left_child() == ZIG && p->parent->if_left_child() == ZIG)
        {
            p->parent->color = BLACK;
            p->grandparent()->color = RED;
            rotate_right(p->parent);
        }
        else if (p->if_left_child() == ZAG && p->parent->if_left_child() == ZAG)
        {
            p->parent->color = BLACK;
            p->grandparent()->color = RED;
            rotate_left(p->parent);
        }
    }
}

template <typename T>
void RBTree<T>::link(Node<T> *parent, Node<T> *child, ZIGZAG zigzag)
{
    if (!parent && child)
    {
        child->color = BLACK;
        child->parent = NULL;
        root = child;
        return;
    }

    if (child)
    {
        child->parent = parent;
    }

    if (zigzag == ZIG)
    {
        parent->left = child;
    }
    else
    {
        parent->right = child;
    }
}

template <typename T>
bool RBTree<T>::delete_value(T data)
{
    Node<T> *p = find_child(root, data);
    if (!p)
    {
        return false;
    }

    // 找到一个left和right都是NULL的替换节点
    p = delete_find_victim(p);

    // 替换节点是root，直接置NULL；
    if (!p->parent)
    {
        p = NULL;
        root = NULL;
        return true;
    }

    delete_case(p);
    // display(PREORDER);
    link(p->parent, NULL, p->if_left_child());
    delete p;

    return true;
}

template <typename T>
Node<T> *RBTree<T>::delete_find_victim(Node<T> *p)
{
    if (!p->left && !p->right)
    {
        return p;
    }

    Node<T> *temp;
    if (p->left)
    {
        temp = p->left;
        while (temp->right)
        {
            temp = temp->right;
        }
    }
    else
    {
        temp = p->right;
        while (temp->left)
        {
            temp = temp->left;
        }
    }

    int tmp_val = temp->value;
    temp->value = p->value;
    p->value = tmp_val;
    return delete_find_victim(temp);
}

template <typename T>
void RBTree<T>::delete_case(Node<T> *p)
{
    // 递归到红色节点或者root，就不用继续借了；
    if (!p->parent || p->color == RED)
    {
        p->color = BLACK;
        return;
    }

    if (p->if_left_child() == ZIG)
    {
        // 2.1.1 -> 2.1.2.3，兄弟节点是红色，调整为黑色
        if (p->sibling()->color == RED)
        {
            p->sibling()->color = BLACK;
            p->parent->color = RED;
            rotate_left(p->parent);
        }
        // 2.1.2.3，以下兄弟节点都是黑色，那么兄弟节点要么没有子节点，要么有红色子节点
        if (!p->sibling()->left && !p->sibling()->right)
        {
            p->sibling()->color = RED;
            delete_case(p->parent);
        }

        // 2.1.2.2 -> 2.1.2.1，兄弟节点的左子节点是红色，调整为2.1.2.1的情况
        if (p->sibling()->left && p->sibling()->left->color == RED)
        {
            p->sibling()->color = RED;
            p->sibling()->left->color = BLACK;
            rotate_right(p->sibling());
        }
        // 2.1.2.1，兄弟节点的右子节点是红色，直接处理掉
        if (p->sibling()->right && p->sibling()->right->color == RED)
        {
            p->sibling()->color = p->parent->color;
            p->parent->color = BLACK;
            p->sibling()->right->color = BLACK;
            rotate_left(p->sibling());
        }
    }
    else
    {
        // 2.2.1 -> 2.2.2.3
        if (p->sibling()->color == RED)
        {
            p->sibling()->color = BLACK;
            p->parent->color = RED;
            rotate_left(p->parent);
        }
        // 2.2.2.3
        if (!p->sibling()->left && !p->sibling()->right)
        {
            p->sibling()->color = RED;
            delete_case(p->parent);
        }

        // 2.2.2.2 -> 2.2.2.1
        if (p->sibling()->right && p->sibling()->right->color == RED)
        {
            p->sibling()->color = RED;
            p->sibling()->right->color = BLACK;
            rotate_right(p->sibling());
        }
        // 2.2.2.1
        if (p->sibling()->left && p->sibling()->left->color == RED)
        {
            p->sibling()->color = p->parent->color;
            p->parent->color = BLACK;
            p->sibling()->left->color = BLACK;
            rotate_left(p->sibling());
        }
    }
}

template <typename T>
void RBTree<T>::rotate_left(Node<T> *p)
{
    Node<T> *gp = p->grandparent();
    Node<T> *fa = p->parent;
    ZIGZAG zigzag = fa->if_left_child();

    fa->right = p->left;
    if (p->left)
    {
        p->left->parent = fa;
    }
    p->left = fa;
    fa->parent = p;

    link(gp, p, zigzag);
}

template <typename T>
void RBTree<T>::rotate_right(Node<T> *p)
{
    Node<T> *gp = p->grandparent();
    Node<T> *fa = p->parent;
    ZIGZAG zigzag = fa->if_left_child();

    fa->left = p->right;
    if (p->right)
    {
        p->right->parent = fa;
    }
    p->right = fa;
    fa->parent = p;

    link(gp, p, zigzag);
}