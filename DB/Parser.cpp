#include "Parser.h"

Parser::Parser()
{
    bp = new BPTree();
}

Parser::~Parser()
{
    delete bp;
    bp = NULL;
}

// 判断输入的指令
void Parser::addressCommand(string command)
{
    // if (strncmp(command, "insert", 6) == 0)
    // {

    //     int *keyIndex = new int;
    //     value_t *insertData = new value_t;

    //     int okNum = sscanf(command, "insert db %d %s %d %s;",
    //                        keyIndex, insertData->name, &(insertData->age), insertData->email);

    //     if (okNum < 3)
    //     {

    //         cout << errorMessage << nextLineHeader;
    //     }
    //     else
    //     {

    //         startTime = clock();

    //         int return_code = insertRecord(duck_db_ptr, keyIndex, insertData);

    //         finishTime = clock();

    //         if (return_code == 0)
    //         {
    //             // cout << ">insert\n";
    //             cout << "> executed insert index:" << *keyIndex << ", time : " << durationTime(&finishTime, &startTime) << " seconds\n"
    //                  << nextLineHeader;
    //         }
    //         else if (return_code == 1)
    //         {
    //             cout << "> failed: already exist index:" << *keyIndex << "\n"
    //                  << nextLineHeader;
    //         }
    //         else
    //         {
    //             cout << "> failed!\n"
    //                  << nextLineHeader;
    //         }
    //     }
    // }
    // else if (strncmp(command, "delete", 6) == 0)
    // {

    //     int *keyIndex = new int;

    //     int okNum = sscanf(command, "delete from db where id=%d;", keyIndex);

    //     if (okNum < 1)
    //     {
    //         cout << errorMessage << nextLineHeader;
    //     }
    //     else
    //     {
    //         startTime = clock();

    //         int return_code = deleteRecord(duck_db_ptr, keyIndex);

    //         finishTime = clock();

    //         if (return_code == 0)
    //         {
    //             cout << "> executed delete index:" << *keyIndex << ", time : " << durationTime(&finishTime, &startTime) << " seconds\n"
    //                  << nextLineHeader;
    //         }
    //         else if (return_code == -1)
    //         {
    //             cout << "> failed ! no index:" << *keyIndex << "\n"
    //                  << nextLineHeader;
    //         }
    //         else
    //         {
    //             cout << "> failed!\n"
    //                  << nextLineHeader;
    //         }
    //     }
    // }
    // else if (strncmp(command, "select", 6) == 0)
    // {

    //     if (!strstr(command, "="))
    //     {

    //         int i_start, i_end;

    //         int okNum = sscanf(command, "select * from db where id in(%d,%d);", &i_start, &i_end);

    //         if (okNum < 2)
    //         {
    //             cout << errorMessage << nextLineHeader;
    //         }
    //         else
    //         {
    //             startTime = clock();

    //             searchAll(duck_db_ptr, &i_start, &i_end);

    //             finishTime = clock();
    //             cout << "> executed search, time : " << durationTime(&finishTime, &startTime) << " seconds\n"
    //                  << nextLineHeader;
    //         }
    //     }
    //     else
    //     {

    //         int *keyIndex = new int;
    //         int okNum = sscanf(command, "select * from db where id=%d;", keyIndex);

    //         if (okNum < 1)
    //         {
    //             cout << errorMessage << nextLineHeader;
    //         }
    //         else
    //         {

    //             value_t *return_val = new value_t;
    //             startTime = clock();

    //             int return_code = searchRecord(duck_db_ptr, keyIndex, return_val);

    //             finishTime = clock();

    //             if (return_code != 0)
    //             {
    //                 cout << "> index:" << *keyIndex << " doesn't exist, time : " << durationTime(&finishTime, &startTime) << " seconds\n"
    //                      << nextLineHeader;
    //             }
    //             else
    //             {
    //                 printTable(keyIndex, return_val);
    //                 cout << "> executed search, time : " << durationTime(&finishTime, &startTime) << " seconds\n"
    //                      << nextLineHeader;
    //             }
    //         }
    //     }
    // }
    // else if (strncmp(command, "update", 6) == 0)
    // {

    //     int *keyIndex = new int;
    //     value_t *updateData = new value_t;

    //     int okNum = sscanf(command, "update db %s %d %s where id=%d;",
    //                        updateData->name, &(updateData->age), updateData->email, keyIndex);

    //     if (okNum < 3)
    //     {
    //         cout << errorMessage << nextLineHeader;
    //     }
    //     else
    //     {
    //         startTime = clock();

    //         int return_code = updateRecord(duck_db_ptr, keyIndex, updateData);

    //         finishTime = clock();

    //         if (return_code == 0)
    //         {
    //             cout << "> executed update index:" << *keyIndex << ", time : " << durationTime(&finishTime, &startTime) << " seconds\n"
    //                  << nextLineHeader;
    //         }
    //         else
    //         {
    //             cout << "> failed! no index:" << *keyIndex << ", time : " << durationTime(&finishTime, &startTime) << " seconds\n"
    //                  << nextLineHeader;
    //         }
    //     }
    // }
}

bool Parser::insertRecord(KeyType key, DataType value)
{
    return bp->insert(key, value);
}

bool Parser::deleteRecord(KeyType index)
{
    return bp->remove(index);
}

bool Parser::updateRecord(KeyType key, DataType value)
{
    return bp->set(key, value);
}

bool Parser::searchRecord(KeyType index, DataType &return_val)
{
    return bp->get(index, return_val);
}

int Parser::searchRecords(KeyType i_start, KeyType i_end, List<DataType> &values)
{
}

int Parser::searchAllRecords(List<DataType> &values)
{
}
