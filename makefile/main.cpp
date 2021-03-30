#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <algorithm>
#include <set>

#include "node.h"
#include "trie.h"

using namespace std;

// 任务1 输⼊读取，第一部分存入 words，第二部分存入 insertWords
void readInput(map<string, int> &words, vector<string> &insertWords)
{
    int n, m;
    cin >> n;

    string word = "";
    for (int i = 0; i < n; i++)
    {
        cin >> word;
        words[word]++;
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> word;
        insertWords.push_back(word);
    }

    // 输出第一个节点
    map<string, int>::iterator iter = words.begin();
    cout << iter->first << endl;

    while (n > 1)
    {
        iter++;
        n--;
    }
    // 输出最后一个节点
    cout << iter->first << endl;
}

// 任务2 构建字典树
BasicTrie *createBasicTrie(map<string, int> &words)
{
    BasicTrie *basicTire = new BasicTrie();
    // 对每一个 word 增加一条路径
    for (map<string, int>::iterator iter = words.begin(); iter != words.end(); iter++)
    {
        basicTire->addPath(iter->first);
    }

    cout << basicTire->getSize() << endl;
    return basicTire;
}

// 任务3 字典树的压缩
void compressBasicTrie(BasicTrie *basicTrie)
{
    basicTrie->compress();
    cout << basicTrie->getSize() << endl;
}

// 任务4 压缩字典树的输出
void inforPrint(BasicTrie *basicTrie)
{
    basicTrie->print();
}

// 任务5 压缩字典树的插⼊
void insertTest(BasicTrie *basicTrie, vector<string> insertWords)
{
    int m = insertWords.size(), count = 0;
    // 挨个插入 word，根据返回值增加 count
    for (int i = 0; i < m; i++)
    {
        count+= basicTrie->insert(insertWords[i]);
    }
    cout << count << endl;
}

int main()
{
    map<string, int> words;
    vector<string> insertWords;

    readInput(words, insertWords);
    BasicTrie *basicTrie = createBasicTrie(words);
    compressBasicTrie(basicTrie);
    inforPrint(basicTrie);
    insertTest(basicTrie, insertWords);
    return 0;
}