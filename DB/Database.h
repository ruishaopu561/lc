#ifndef DATABASE_H
#define DATABASE_H

#include "Table.h"

using namespace std;

class Database
{
public:
    Database();
    ~Database();

    void printHelpMessage();
    void addressCommand(string);
    void printTable(int, DataType);
    bool is_file_exist(const char *);

private:
    Table *table;

    string toLowerCase(string);
    string clearUnneceBlank(string);
};

#endif /* DATABASE_H */