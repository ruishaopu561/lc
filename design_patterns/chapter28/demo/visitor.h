#ifndef VISITOR_H
#define VISITOR_H

#include <string>

class ConcreteElementA;
class ConcreteElementB;

class Visitor
{
private:
    std::string name;

public:
    Visitor(std::string _name) : name(_name){};
    ~Visitor(){};
    std::string getName();
    virtual void visitConcreteElementA(ConcreteElementA *concreteElementA) = 0;
    virtual void visitConcreteElementB(ConcreteElementB *concreteElementB) = 0;
};

class ConcreteVisitor1 : public Visitor
{
public:
    ConcreteVisitor1(std::string _name) : Visitor(_name){};
    ~ConcreteVisitor1(){};
    void visitConcreteElementA(ConcreteElementA *concreteElementA);
    void visitConcreteElementB(ConcreteElementB *concreteElementB);
};

class ConcreteVisitor2 : public Visitor
{
public:
    ConcreteVisitor2(std::string _name) : Visitor(_name){};
    ~ConcreteVisitor2(){};
    void visitConcreteElementA(ConcreteElementA *concreteElementA);
    void visitConcreteElementB(ConcreteElementB *concreteElementB);
};

#endif /*VISITOR_H*/