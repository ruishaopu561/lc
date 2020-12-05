#include "element.h"
#include "visitor.h"

std::string Element::getName()
{
    return name;
}

void ConcreteElementA::accept(Visitor *visitor)
{
    visitor->visitConcreteElementA(this);
}

void ConcreteElementB::accept(Visitor *visitor)
{
    visitor->visitConcreteElementB(this);
}