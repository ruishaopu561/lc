#ifndef OBJECTSTRUCTURE_H
#define OBJECTSTRUCTURE_H

#include <vector>

#include "element.h"
#include "visitor.h"

class ObjectStructure
{
private:
    std::vector<Element *> elements;

public:
    ObjectStructure(){};
    ~ObjectStructure(){};
    void attach(Element *element);
    void detach(Element *element);
    void display(Visitor *visitor);
};

void ObjectStructure::attach(Element *element)
{
    elements.push_back(element);
}

void ObjectStructure::detach(Element *element)
{
    for (int i = 0; i < elements.size(); i++)
    {
        if (elements[i] == element)
        {
            elements.erase(elements.begin() + i);
        }
    }
}

void ObjectStructure::display(Visitor *visitor)
{
    for (int i = 0; i < elements.size(); i++)
    {
        elements[i]->accept(visitor);
    }
}

#endif /*OBJECTSTRUCTURE_H*/