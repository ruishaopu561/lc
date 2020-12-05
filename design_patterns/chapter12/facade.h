#ifndef _FACADE_
#define _FACADE_

#include <iostream>

class SubsystemA
{
public:
    SubsystemA(){};
    ~SubsystemA(){};
    void method1();
};

void SubsystemA::method1()
{
    std::cout << "Subsystem method 1." << std::endl;
}

class SubsystemB
{
public:
    SubsystemB(){};
    ~SubsystemB(){};
    void method2();
};

void SubsystemB::method2()
{
    std::cout << "Subsystem method 2." << std::endl;
}

class SubsystemC
{
public:
    SubsystemC(){};
    ~SubsystemC(){};
    void method3();
};

void SubsystemC::method3()
{
    std::cout << "Subsystem method 3." << std::endl;
}

class SubsystemD
{
public:
    SubsystemD(){};
    ~SubsystemD(){};
    void method4();
};

void SubsystemD::method4()
{
    std::cout << "Subsystem method 4." << std::endl;
}

class Facade
{
public:
    SubsystemA *a;
    SubsystemB *b;
    SubsystemC *c;
    SubsystemD *d;
    Facade();
    ~Facade();
    void methodA();
    void methodB();
};

Facade::Facade()
{
    a = new SubsystemA();
    b = new SubsystemB();
    c = new SubsystemC();
    d = new SubsystemD();
}

Facade::~Facade()
{
    delete a;
    delete b;
    delete c;
    delete d;
}

void Facade::methodA()
{
    std::cout << "methods A() " << std::endl;
    a->method1();
    b->method2();
    d->method4();
}

void Facade::methodB()
{
    std::cout << "methods B()" << std::endl;
    b->method2();
    c->method3();
}

#endif /*_FACADE_*/
