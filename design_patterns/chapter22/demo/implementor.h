#ifndef IMPLEMENTOR_H
#define IMPLEMENTOR_H

#include <iostream>

class Implementor
{
public:
    Implementor(){};
    ~Implementor(){};
    virtual void operation() = 0;
};

class ConcreteImplementorA : public Implementor
{
public:
    ConcreteImplementorA(){};
    ~ConcreteImplementorA(){};
    void operation();
};

void ConcreteImplementorA::operation()
{
    std::cout << "具体实现A的方法执行" << std::endl;
}

class ConcreteImplementorB : public Implementor
{
public:
    ConcreteImplementorB(){};
    ~ConcreteImplementorB(){};
    void operation();
};

void ConcreteImplementorB::operation()
{
    std::cout << "具体实现B的方法执行" << std::endl;
}

#endif /*IMPLEMENTOR_H*/