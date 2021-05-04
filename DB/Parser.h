#ifndef PARSER_H
#define PARSER_H

#include "BPTree.h"

using namespace std;

class Parser
{
public:
    Parser();
    ~Parser();

    // 判断输入的指令
    void addressCommand(string command);

private:
    BPTree *bp;

    bool insertRecord(KeyType, DataType);
    bool deleteRecord(KeyType);
    bool updateRecord(KeyType, DataType);
    bool searchRecord(KeyType, DataType &);
    int searchRecords(KeyType, KeyType, List<DataType> &);
    int searchAllRecords(List<DataType> &);
};

#endif /* PARSER_H */