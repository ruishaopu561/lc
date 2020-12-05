#include "country.h"
#include "unitedNations.h"

UnitedNations *Country::getMediator()
{
    return mediator;
}

void USA::declare(std::string message)
{
    getMediator()->declare(message, this);
}

void USA::getMessage(std::string message)
{
    std::cout << "美国获得对方信息：" << message << std::endl;
}

void Irap::declare(std::string message)
{
    getMediator()->declare(message, this);
}

void Irap::getMessage(std::string message)
{
    std::cout << "伊拉克获得对方信息：" << message << std::endl;
}