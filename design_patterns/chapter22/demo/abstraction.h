#ifndef ABSTRACTION_H
#define ABSTRACTION_H

#include "implementor.h"

class Abstraction
{
public:
    Implementor *implementor;

    Abstraction(){};
    ~Abstraction(){};
    void setImplementor(Implementor *_implementor);
    virtual void operation() = 0;
};

void Abstraction::setImplementor(Implementor *_implementor)
{
    implementor = _implementor;
}

class RefinedAbstraction : public Abstraction
{
public:
    RefinedAbstraction(){};
    ~RefinedAbstraction(){};
    void operation();
};

void RefinedAbstraction::operation()
{
    implementor->operation();
}

#endif /*ABSTRACTION_H*/