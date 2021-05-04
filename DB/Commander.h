#ifndef COMMANDER_H
#define COMMANDER_H

#include "Parser.h"

const char errorMessage[] = "> your input is invalid, print \"help\" for more infomation!\n";
const char nextLineHeader[] = "> ";
const char exitMessage[] = "exit.\n";

using namespace std;

class Commander
{
public:
    Commander();
    ~Commander();

    void printHelpMessage();
    void addressCommand(string);
    void printTable(int, DataType);
    bool is_file_exist(const char *);

private:
    Parser *parser;

    string toLowerCase(string);
    string clearUnneceBlank(string);
};

#endif /* COMMANDER_H */