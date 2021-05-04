#include "Table.h"

Table::Table()
{
    bp = new BPTree();
}

Table::~Table()
{
    delete bp;
    bp = NULL;
}

ERROR Table::insertRecord(string command)
{
    int key;
    char data[COMMANDLENGTH];
    if (sscanf(command.c_str(), "insert into db %d %s;", &key, data) < 2)
    {
        return SYNTAXERROR;
    }
    string value(data);
    return bp->insert(key, value);
}

ERROR Table::deleteRecord(string command)
{
    int key;
    if (sscanf(command.c_str(), "delete from db where id=%d;", &key) < 1)
    {
        return SYNTAXERROR;
    }
    return bp->remove(key);
}

ERROR Table::updateRecord(string command)
{
    int key;
    char data[COMMANDLENGTH];
    if (sscanf(command.c_str(), "update db %s where id=%d", data, &key) < 2)
    {
        return SYNTAXERROR;
    }
    string value(data);
    return bp->set(key, value);
}

ERROR Table::searchRecord(string command, DataType &value)
{
    int key;
    if (sscanf(command.c_str(), "select * from db where id=%d;", &key) < 1)
    {
        return SYNTAXERROR;
    }
    return bp->get(key, value);
}

ERROR Table::searchRecords(KeyType i_start, KeyType i_end, List<DataType> &values)
{
    return OK;
}

ERROR Table::searchAllRecords(List<DataType> &values)
{
    return OK;
}
