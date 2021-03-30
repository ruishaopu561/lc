#include <iostream>
#include <string>
#include <map>

#include "Node.h"
#include "Trie.h"

using namespace std;

BasicTrie::BasicTrie()
{
    root = new Node();
    size = 1;
}

BasicTrie::~BasicTrie()
{
    delete root;
}

int BasicTrie::getSize()
{
    return size;
}

void BasicTrie::setSize()
{
    size = root->setSize();
}

void BasicTrie::addPath(string word)
{
    Node *p = root;
    int len = word.size();
    for (int i = 0; i < len; i++)
    {
        string value = word.substr(i, 1);
        if (p->children.find(value) == p->children.end())
        {
            p->children[value] = new Node(value, false);
            size++;
        }
        p = p->children[value];
    }
    p->end = true;
}

void BasicTrie::compress()
{
    root->compress();
    setSize();
}

void BasicTrie::print()
{
    root->setDepth(0);
    root->print();
}

int BasicTrie::insert(string word)
{
    int index = root->getSameSize(word);

    // 情况 5，需要注意，root 值为 null 时，word 需要插入到 root 子节点中
    // 而不是单纯用情况 5 处理
    if (index == 0 && root->chs.size() != 0)
    {
        Node *newChild = new Node(word, true);
        Node *newRoot = new Node();
        newRoot->addChild(root);
        newRoot->addChild(newChild);
        root = newRoot;
        return 0;
    }
    else
    {
        return root->insert(word, index);
    }
}