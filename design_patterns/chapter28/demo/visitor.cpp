#include "visitor.h"
#include "element.h"

#include <iostream>

std::string Visitor::getName()
{
    return name;
}

void ConcreteVisitor1::visitConcreteElementA(ConcreteElementA *concreteElementA)
{
    std::cout << concreteElementA->getName() << "  " << getName() << std::endl;
}

void ConcreteVisitor1::visitConcreteElementB(ConcreteElementB *concreteElementB)
{
    std::cout << concreteElementB->getName() << "  " << getName() << std::endl;
}

void ConcreteVisitor2::visitConcreteElementA(ConcreteElementA *concreteElementA)
{
    std::cout << concreteElementA->getName() << "  " << getName() << std::endl;
}

void ConcreteVisitor2::visitConcreteElementB(ConcreteElementB *concreteElementB)
{
    std::cout << concreteElementB->getName() << "  " << getName() << std::endl;
}
