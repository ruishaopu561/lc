#ifndef WAITER_H
#define WAITER_H

#include <iostream>
#include <vector>

#include "command.h"

class Waiter
{
private:
    std::vector<Command *> orders;

public:
    Waiter(){};
    ~Waiter(){};
    void setOrder(Command *command);
    void cancelOrder(Command *command);
    void notify();
};

void Waiter::setOrder(Command *command)
{
    if (command->getName() == "烤鸡翅")
    {
        std::cout << "服务员：鸡翅没有了，请点别的烧烤。" << std::endl;
    }
    else
    {
        orders.push_back(command);
        std::cout << "增加订单：" << command->getName() << std::endl;
    }
}

void Waiter::cancelOrder(Command *command)
{
    for (int i = 0; i < orders.size(); i++)
    {
        if (orders[i] == command)
        {
            orders.erase(orders.begin() + i);
        }
    }
    std::cout << "取消订单：" << command->getName() << std::endl;
}

void Waiter::notify()
{
    for (int i = 0; i < orders.size(); i++)
    {
        orders[i]->excuteCommand();
    }
}

#endif /*WAITER_H*/
