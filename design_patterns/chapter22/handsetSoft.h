#ifndef HANDSETSOFT_H
#define HANDSETSOFT_H

#include <iostream>

class HandsetSoft
{
public:
    HandsetSoft(){};
    ~HandsetSoft(){};
    virtual void run() = 0;
};

class HandsetGame : public HandsetSoft
{
public:
    HandsetGame(){};
    ~HandsetGame(){};
    void run();
};

void HandsetGame::run()
{
    std::cout << "运行手机游戏" << std::endl;
}

class HandsetAddressList : public HandsetSoft
{
public:
    HandsetAddressList(){};
    ~HandsetAddressList(){};
    void run();
};

void HandsetAddressList::run()
{
    std::cout << "运行手机通讯录" << std::endl;
}

#endif /*HANDSETSOFT_H*/