#ifndef ELEMENT_H
#define ELEMENT_H

#include <string>

class Visitor;

class Element
{
private:
    std::string name;

public:
    Element(std::string _name) : name(_name){};
    ~Element(){};
    std::string getName();
    virtual void accept(Visitor *visitor) = 0;
};

class ConcreteElementA : public Element
{
public:
    ConcreteElementA(std::string _name) : Element(_name){};
    ~ConcreteElementA(){};
    void accept(Visitor *visitor);
};

class ConcreteElementB : public Element
{
public:
    ConcreteElementB(std::string _name) : Element(_name){};
    ~ConcreteElementB(){};
    void accept(Visitor *visitor);
};

#endif /*ELEMENT_H*/