#ifndef _ADAPTEE_
#define _ADAPTEE_

#include <iostream>

class Adaptee
{
public:
    Adaptee(){};
    ~Adaptee(){};
    void specificRequest();
};

void Adaptee::specificRequest()
{
    std::cout << "specific request." << std::endl;
}

#endif /*_ADAPTEE_*/