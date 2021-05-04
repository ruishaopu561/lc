#include "Database.h"

Database::Database()
{
    table = new Table();
}

Database::~Database()
{
    delete table;
    table = NULL;
}

void Database::addressCommand(string command)
{
    if (command.size() > COMMANDLENGTH)
    {
        errorReport(COMMANDTOOLONG);
        return;
    }

    command = clearUnneceBlank(command);
    command = toLowerCase(command);

    if (command.substr(0, 4) == "exit")
    {
        cout << exitMessage;
        exit(0);
    }
    else if (command.substr(0, 4) == "help")
    {
        printHelpMessage();
    }
    else if (command.substr(0, 6) == "create")
    {
        errorReport(OK);
    }
    else if (command.substr(0, 3) == "use")
    {
        errorReport(OK);
    }
    else if (command.substr(0, 4) == "drop")
    {
        errorReport(OK);
    }
    else if (command.substr(0, 6) == "rename")
    {
        errorReport(OK);
    }
    else if (command.substr(0, 6) == "insert")
    {
        ERROR err = table->insertRecord(command);
        errorReport(err);
    }
    else if (command.substr(0, 6) == "delete")
    {
        ERROR err = table->deleteRecord(command);
        errorReport(err);
    }
    else if (command.substr(0, 6) == "update")
    {
        ERROR err = table->updateRecord(command);
        errorReport(err);
    }
    else if (command.substr(0, 6) == "select")
    {
        DataType value;
        ERROR err = table->searchRecord(command, value);
        errorReport(err);
        if (err == OK)
        {
            cout << value << endl;
        }
    }
    else
    {
        errorReport(SYNTAXERROR);
    }
}

void Database::printTable(int, DataType)
{
}

bool Database::is_file_exist(const char *fileName)
{
    return true;
}

void Database::printHelpMessage()
{
    cout << "*********************************************************************************************" << endl
         << endl
         << " 				Welcome to the DB!\n"
         << "				DB file locates in \"./data/db.bin\" \n"
         << " 				author: Rui Shaopu\n"
         << "				2021-05-04\n"
         << endl
         << "*********************************************************************************************" << endl
         << "  help                                                         print help message;" << endl
         << "  exit                                                         exit program;" << endl
         << "  reset                                                        delete db file;" << endl
         << "  insert db {index} {name};                                    insert record;" << endl
         << "  delete from db where id={index};                             delete record;" << endl
         << "  update db {name} where id={index};                           update a record;" << endl
         << "  select * from db where id={index};                           search a record by index;" << endl
         << "  select * from db where id in({minIndex},{maxIndex});         search records between indexs;" << endl
         << "*********************************************************************************************" << endl
         << endl;
}

string Database::toLowerCase(string str)
{
    string ret = "";
    int size = str.size();
    for (int i = 0; i < size; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            ret += (str[i] + 32);
        }
        else
        {
            ret += str[i];
        }
    }
    return ret;
}

string Database::clearUnneceBlank(string str)
{
    string ret = "";
    bool blank = false;
    int size = str.size(), index = 0;
    // 清除头部空格
    while (index < size && str[index] == ' ')
    {
        index++;
    }
    str = str.substr(index);

    size = str.size();
    index = size - 1;
    // 清除尾部空格
    while (index >= 0 && str[index] == ' ')
    {
        index--;
    }
    str = str.substr(0, index + 1);

    size = str.size();
    index = 0;
    // 清除中间空格
    for (; index < size; index++)
    {
        if (str[index] != ' ')
        {
            if (blank)
            {
                ret += ' ';
                blank = false;
            }
            ret += str[index];
        }
        else
        {
            blank = true;
        }
    }

    return ret;
}

void Database::errorReport(ERROR err)
{
    switch (err)
    {
    case OK:
        cout << successMessage;
        break;
    case SYNTAXERROR:
        cout << syntaxEerrorMessage;
        break;
    case EXIST:
        cout << existMessage;
        break;
    case NONEXIST:
        cout << nonExistMessage;
        break;
    case COMMANDTOOLONG:
        cout << commandLongMessage;
        break;
    default:
        return;
    }
}
