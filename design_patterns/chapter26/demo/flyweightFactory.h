#ifndef FLYWEIGHTFACTORY_H
#define FLYWEIGHTFACTORY_H

#include <map>
#include <string>

#include "flyweight.h"

class FlyweightFactory
{
private:
    std::map<std::string, Flyweight *> flyweights;

public:
    FlyweightFactory();
    ~FlyweightFactory();
    Flyweight *getFlyweight(std::string key);
};

FlyweightFactory::FlyweightFactory()
{
    flyweights["X"] = new ConcreteFlyweight();
    flyweights["Y"] = new ConcreteFlyweight();
    flyweights["Z"] = new ConcreteFlyweight();
}

Flyweight *FlyweightFactory::getFlyweight(std::string key)
{
    return flyweights[key];
}

#endif /*FLYWEIGHTFACTORY_H*/