#ifndef _TARGET_
#define _TARGET_

#include <iostream>

#include "adaptee.h"

class Target
{
public:
    Target(){};
    ~Target(){};
    virtual void request();
};

void Target::request()
{
    std::cout << "common request." << std::endl;
}

class Adapter : public Target
{
private:
    Adaptee *adaptee;

public:
    Adapter() : adaptee(new Adaptee()){};
    ~Adapter(){};
    void request();
};

void Adapter::request()
{
    adaptee->specificRequest();
}

#endif /*_TARGET_*/