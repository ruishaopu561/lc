#include <iostream>

#include "Node.h"
#include "BPTree.h"

using namespace std;

int main()
{
    BPTree *bp = new BPTree();
    cout << "new succeed!" << endl;

    for (int i = 1; i < 16; i++)
    {
        bp->insert(i, "aa");
        bp->iterate();
        bp->printTree();
        cout << endl;
    }
    cout << "insert 1 succeed!" << endl;
    cout << "iterate succeed!" << endl;
    cout << "print tree succeed!" << endl;

    bp->set(5, "ae");
    bp->set(7, "ag");
    bp->set(3, "ac");
    bp->iterate();
    cout << "set new value succeed!" << endl;
}