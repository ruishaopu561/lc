#ifndef FLYWEIGHT_H
#define FLYWEIGHT_H

#include <iostream>

class Flyweight
{
public:
    Flyweight(){};
    ~Flyweight(){};
    virtual void operation(int extrinsicstate) = 0;
};

class ConcreteFlyweight : public Flyweight
{
public:
    ConcreteFlyweight(){};
    ~ConcreteFlyweight(){};
    void operation(int extrinsicstate);
};

void ConcreteFlyweight::operation(int extrinsicstate)
{
    std::cout << "具体Flyweight：" << extrinsicstate << std::endl;
}

// 解决不需要共享的对象的问题
class UnsharedConcreteFlyweight : public Flyweight
{
public:
    UnsharedConcreteFlyweight(){};
    ~UnsharedConcreteFlyweight(){};
    void operation(int extrinsicstate);
};

void UnsharedConcreteFlyweight::operation(int extrinsicstate)
{
    std::cout << "不共享的具体Flyweight：" << extrinsicstate << std::endl;
}

#endif /*FLYWEIGHT_H*/