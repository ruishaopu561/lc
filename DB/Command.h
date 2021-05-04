#ifndef COMMAND_H
#define COMMAND_H

const int COMMANDLENGTH = 256;
const char nextLineHeader[] = "> ";
const char exitMessage[] = "exit.\n";

enum COMMAND
{
    // table 指令
    INSERT,
    DELETE,
    UPDATE,
    SELECT,

    // DB 指令
    OTHER
    // CREATE,
    // USE,
    // DROP,
    // RENAME,
    // HELP,
    // EXIT,
};

#endif // !COMMAND_H
