#ifndef TRIE_H
#define TRIE_H

#include <string>

#include "Node.h"

using namespace std;

class BasicTrie
{
public:
    Node *root;
    int size;
    BasicTrie();
    ~BasicTrie();
    int getSize();
    void setSize();
    void addPath(string word);
    void compress();
    void print();
    int insert(string word);
};

#endif /*TRIE_H*/