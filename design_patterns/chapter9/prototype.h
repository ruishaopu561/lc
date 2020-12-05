#ifndef _PROTOTYPE_
#define _PROTOTYPE_

#include <string>

class Prototype
{
public:
    Prototype(){};
    ~Prototype(){};
    virtual Prototype *clone() = 0;
};

class ConcretePrototype1: public Prototype
{
public:
    std::string id;

    ConcretePrototype1():id(0){};
    ConcretePrototype1(std::string _id):id(_id){};
    ConcretePrototype1(const ConcretePrototype1 &rhs);
    ~ConcretePrototype1(){};
    virtual Prototype* clone();
};

ConcretePrototype1::ConcretePrototype1(const ConcretePrototype1 &rhs)
{
    id = rhs.id;
}

Prototype* ConcretePrototype1::clone()
{
    return new ConcretePrototype1(*this);
}

#endif /*_PROTOTYPE_*/