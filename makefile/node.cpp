#include "Node.h"

using namespace std;

void Node::compress()
{
    if (children.size() == 0)
    {
        return;
    }
    while (!end && children.size() == 1)
    {
        Node *child = children.begin()->second;
        chs += child->chs;
        end = child->end;
        children.clear();
        for (map<string, Node *>::iterator iter = child->children.begin(); iter != child->children.end(); iter++)
        {
            children.insert(make_pair(iter->first, iter->second));
        }
    }
    for (map<string, Node *>::iterator iter = children.begin(); iter != children.end(); iter++)
    {
        iter->second->compress();
    }
}

int Node::setSize()
{
    int size = 1;
    for (map<string, Node *>::iterator iter = children.begin(); iter != children.end(); iter++)
    {
        size += iter->second->setSize();
    }
    return size;
}

void Node::setDepth(int _depth)
{
    depth = _depth;
    for (map<string, Node *>::iterator iter = children.begin(); iter != children.end(); iter++)
    {
        iter->second->setDepth(_depth + 1);
    }
}

void Node::print()
{
    for (int i = 0; i < depth; i++)
    {
        cout << " ";
    }
    cout << chs << endl;

    for (map<string, Node *>::iterator iter = children.begin(); iter != children.end(); iter++)
    {
        iter->second->print();
    }
}

bool Node::insert(string word, int index)
{
    // 情况 1 没有分裂
    if (index == word.size() && index == chs.size())
    {
        end = true;
        return 0;
        // 情况 3 的分裂部分
    }
    else if (index == word.size() && index < chs.size())
    {
        Node *child = new Node(chs.substr(index), end);
        chs = chs.substr(0, index);
        end = true;
        for (map<string, Node *>::iterator iter = children.begin(); iter != children.end(); iter++)
        {
            child->addChild(iter->second);
        }
        children.clear();
        addChild(child);
        return 1;
        // 情况 2、3
    }
    else if (index < word.size() && index == chs.size())
    {
        string value = word.substr(index);
        for (map<string, Node *>::iterator iter = children.begin(); iter != children.end(); iter++)
        {
            // 情况 3，有分裂
            int i = iter->second->getSameSize(value);
            if (i > 0)
            {
                return iter->second->insert(value, i);
            }
        }
        // 情况 2 没有分裂
        Node *child = new Node(value, true);
        addChild(child);
        return 0;
        // 情况 4 有分裂
    }
    else if (index < word.size() && index < chs.size())
    {
        Node *child1 = new Node(chs.substr(index), end);
        Node *child2 = new Node(word.substr(index), true);
        chs = chs.substr(0, index);
        for (map<string, Node *>::iterator iter = children.begin(); iter != children.end(); iter++)
        {
            child1->addChild(iter->second);
        }
        children.clear();
        addChild(child1);
        addChild(child2);
        return 1;
    }
    return 0;
}

// 往 children 中加入节点
void Node::addChild(Node *child)
{
    children.insert(make_pair(child->chs, child));
}

// 计算 当前节点的 chs 与 str 的共同子串的长度（子串从头开始）
int Node::getSameSize(string str)
{
    int chsSize = chs.size(), wordSize = str.size();
    int len = (chsSize < wordSize) ? chsSize : wordSize;
    int index = 0;
    // 得出公共长度
    for (; index < len; index++)
    {
        if (chs[index] != str[index])
        {
            break;
        }
    }

    return index;
}
