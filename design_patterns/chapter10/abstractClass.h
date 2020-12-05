#ifndef _ABSTRACTCLASS_
#define _ABSTRACTCLASS_

#include <iostream>

class AbstractClass
{
public:
    AbstractClass(){};
    ~AbstractClass(){};
    virtual void primitiveOperation1() = 0;
    virtual void primitiveOperation2() = 0;

    void TemplateMethod();
};

void AbstractClass::TemplateMethod()
{
    primitiveOperation1();
    primitiveOperation2();
    std::cout << "other public operations...\n" << std::endl;
}

class ConcreteClassA : public AbstractClass
{
public:
    ConcreteClassA(){};
    ~ConcreteClassA(){};
    virtual void primitiveOperation1();
    virtual void primitiveOperation2();
};

void ConcreteClassA::primitiveOperation1()
{
    std::cout << "Concrete class A operation 1 implementation." << std::endl;
}

void ConcreteClassA::primitiveOperation2()
{
    std::cout << "Concrete class A operation 2 implementation." << std::endl;
}

class ConcreteClassB : public AbstractClass
{
public:
    ConcreteClassB(){};
    ~ConcreteClassB(){};
    virtual void primitiveOperation1();
    virtual void primitiveOperation2();
};

void ConcreteClassB::primitiveOperation1()
{
    std::cout << "Concrete class B operation 1 implementation." << std::endl;
}

void ConcreteClassB::primitiveOperation2()
{
    std::cout << "Concrete class B operation 2 implementation." << std::endl;
}

#endif /*_ABSTRACTCLASS_*/
