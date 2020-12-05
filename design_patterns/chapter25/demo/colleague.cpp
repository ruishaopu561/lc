#include "colleague.h"
#include "mediator.h"

#include <iostream>

Mediator *Colleague::getMediator()
{
    return mediator;
}

void ConcreteColleague1::send(std::string message)
{
    getMediator()->send(message, this);
}

void ConcreteColleague1::notify(std::string message)
{
    std::cout << "同事1得到信息：" << message << std::endl;
}

void ConcreteColleague2::send(std::string message)
{
    getMediator()->send(message, this);
}

void ConcreteColleague2::notify(std::string message)
{
    std::cout << "同事2得到信息：" << message << std::endl;
}
