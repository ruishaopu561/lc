#ifndef HANDLER_H
#define HANDLER_H

#include <iostream>
#include <string>

class Handler
{
public:
    Handler *successor;
    std::string name;
    
    Handler(std::string _name) : name(_name){};
    ~Handler(){};
    void setSuccessor(Handler *_successor);
    virtual void handleRequest(int request) = 0;
};

void Handler::setSuccessor(Handler *_successor)
{
    successor = _successor;
}

class ConcreteHandler1 : public Handler
{
public:
    ConcreteHandler1(std::string _name) : Handler(_name){};
    ~ConcreteHandler1(){};
    void handleRequest(int request);
};

void ConcreteHandler1::handleRequest(int request)
{
    if (request >= 0 && request < 10)
    {
        std::cout << name << " " << request << std::endl;
    }
    else if (successor != NULL)
    {
        successor->handleRequest(request);
    }
}

class ConcreteHandler2 : public Handler
{
public:
    ConcreteHandler2(std::string _name) : Handler(_name){};
    ~ConcreteHandler2(){};
    void handleRequest(int request);
};

void ConcreteHandler2::handleRequest(int request)
{
    if (request >= 10 && request < 20)
    {
        std::cout << name << " " << request << std::endl;
    }
    else if (successor != NULL)
    {
        successor->handleRequest(request);
    }
}

class ConcreteHandler3 : public Handler
{
public:
    ConcreteHandler3(std::string _name) : Handler(_name){};
    ~ConcreteHandler3(){};
    void handleRequest(int request);
};

void ConcreteHandler3::handleRequest(int request)
{
    if (request >= 20 && request < 30)
    {
        std::cout << name << " " << request << std::endl;
    }
    else if (successor != NULL)
    {
        successor->handleRequest(request);
    }
}

#endif /*HANDLER_H*/