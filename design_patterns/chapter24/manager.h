#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <string>

#include "request.h"

class Manager
{
private:
    std::string name;
    Manager *superior;

public:
    Manager(std::string _name) : name(_name){};
    ~Manager(){};
    std::string getName();
    Manager *getSuperior();
    void setSuperior(Manager *_superior);
    virtual void handleRequest(Request *request) = 0;
};

std::string Manager::getName()
{
    return name;
}

Manager *Manager::getSuperior()
{
    return superior;
}

void Manager::setSuperior(Manager *_superior)
{
    superior = _superior;
}

class CommonManager : public Manager
{
public:
    CommonManager(std::string _name) : Manager(_name){};
    ~CommonManager(){};
    void handleRequest(Request *request);
};

void CommonManager::handleRequest(Request *request)
{
    if (request->getRequestType() == "请假" && request->getNumber() <= 2)
    {
        std::cout << getName() << " " << request->getRequestContent() << " 数量 " << request->getNumber() << " 被批准" << std::endl;
    }
    else
    {
        if (getSuperior() != NULL){
            getSuperior()->handleRequest(request);
        }
    }
}

class Majordomo : public Manager
{
public:
    Majordomo(std::string _name) : Manager(_name){};
    ~Majordomo(){};
    void handleRequest(Request *request);
};

void Majordomo::handleRequest(Request *request)
{
    if (request->getRequestType() == "请假" && request->getNumber() <= 5)
    {
        std::cout << getName() << " " << request->getRequestContent() << " 数量 " << request->getNumber() << " 被批准" << std::endl;
    }
    else
    {
        if (getSuperior() != NULL){
            getSuperior()->handleRequest(request);
        }
    }
}

class GeneralManager : public Manager
{
public:
    GeneralManager(std::string _name) : Manager(_name){};
    ~GeneralManager(){};
    void handleRequest(Request *request);
};

void GeneralManager::handleRequest(Request *request)
{
    if (request->getRequestType() == "请假")
    {
        std::cout << getName() << " " << request->getRequestContent() << " 数量 " << request->getNumber() << " 被批准" << std::endl;
    }
    else if (request->getRequestType() == "加薪" && request->getNumber() <= 500)
    {
        std::cout << getName() << " " << request->getRequestContent() << " 数量 " << request->getNumber() << " 被批准" << std::endl;
    }
    else if (request->getRequestType() == "加薪" && request->getNumber() > 500)
    {
        std::cout << getName() << " " << request->getRequestContent() << " 数量 " << request->getNumber() << " 再说吧" << std::endl;
    }
}

#endif /*MANAGER_H*/