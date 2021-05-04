#ifndef TABLE_H
#define TABLE_H

#include "BPTree.h"
#include "Error.h"
#include "Command.h"

using namespace std;

class Table
{
public:
    Table();
    ~Table();

    ERROR insertRecord(string);
    ERROR deleteRecord(string);
    ERROR updateRecord(string);
    ERROR searchRecord(string, DataType &);

private:
    BPTree *bp;

    ERROR searchRecords(KeyType, KeyType, List<DataType> &);
    ERROR searchAllRecords(List<DataType> &);
};

#endif /* TABLE_H */