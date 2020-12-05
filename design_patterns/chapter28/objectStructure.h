#ifndef OBJECTSTRUCTURE_H
#define OBJECTSTRUCTURE_H

#include <vector>

#include "person.h"
#include "action.h"

class ObjectStructure
{
private:
    std::vector<Person *> elements;

public:
    ObjectStructure(){};
    ~ObjectStructure(){};
    void attach(Person *element);
    void detach(Person *element);
    void display(Action *visitor);
};

void ObjectStructure::attach(Person *element)
{
    elements.push_back(element);
}

void ObjectStructure::detach(Person *element)
{
    for (int i = 0; i < elements.size(); i++)
    {
        if (elements[i] == element)
        {
            elements.erase(elements.begin() + i);
        }
    }
}

void ObjectStructure::display(Action *visitor)
{
    for (int i = 0; i < elements.size(); i++)
    {
        elements[i]->accept(visitor);
    }
}

#endif /*OBJECTSTRUCTURE_H*/