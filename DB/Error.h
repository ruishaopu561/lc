#ifndef ERROR_H
#define ERROR_H

const char successMessage[] = "OK!\n";
const char syntaxEerrorMessage[] = "> Syntax error: your input is invalid, print \"help\" for more infomation!\n";
const char existMessage[] = "> failed! key already exists!\n";
const char nonExistMessage[] = "> failed! no such key exists!\n";
const char commandLongMessage[] = "Command is too long!\n";

using namespace std;

enum ERROR
{
    OK,
    SYNTAXERROR,
    EXIST,
    NONEXIST,
    COMMANDTOOLONG
};

#endif /* ERROR_H */