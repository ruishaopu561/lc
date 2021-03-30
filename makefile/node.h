#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

class Node
{
public:
    string chs;
    bool end;
    int depth;
    map<string, Node *> children;
    Node() : chs(""), end(false), depth(0){};
    Node(string _chs, bool _end) : chs(_chs), end(_end), depth(0){};
    ~Node(){};

    void compress();
    int setSize();
    void setDepth(int _depth);
    void print();
    bool insert(string word, int index);
    // 往 children 中加入节点
    void addChild(Node *child);
    // 计算 当前节点的 chs 与 str 的共同子串的长度（子串从头开始）
    int getSameSize(string str);
};

#endif /*NODE_H*/