#include <iostream>

#include "List.h"
#include "Node.h"
#include "BPTree.h"

using namespace std;

void test1()
{
    BPTree *bp = new BPTree();
    cout << "new succeed!" << endl;

    for (int i = 4; i < 16; i++)
    {
        bp->insert(i, "aa");
        bp->iterate();
        bp->printTree();
        cout << endl;
    }
    cout << "insert succeed!" << endl;
    cout << "iterate succeed!" << endl;
    cout << "print tree succeed!" << endl;

    bp->insert(1, "aa");
    bp->iterate();
    bp->printTree();

    bp->set(5, "ae");
    bp->set(7, "ag");
    bp->set(3, "ac");
    bp->set(1, "aA");
    bp->set(15, "ao");
    // bp->iterate();
    bp->printTree();
    cout << "set new value succeed!" << endl;

    bp->remove(6);
    bp->remove(10);
    bp->iterate();
    bp->printTree();
    cout << "remove 1eaf node succeed!" << endl;

    bp->remove(5);
    bp->iterate();
    bp->printTree();
    cout << "remove internal node succeed!" << endl;

    bp->remove(1);
    bp->iterate();
    bp->printTree();
    cout << "remove internal node succeed!" << endl;
}

void test2()
{
    // create database **;
    // use database **;
    // create table **(int key, string value);
    // select * from **;
    // insert into ** value(key1, value1);
}

int main()
{
    test1();
    test2();
}
