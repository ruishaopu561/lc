#ifndef _ORIGINATOR_
#define _ORIGINATOR_

#include <iostream>
#include <string>

#include "memento.h"

class Originator
{
private:
    std::string state;

public:
    Originator(){};
    ~Originator(){};
    std::string getState();
    void setState(std::string _state);
    Memento *createMemento();
    void setMemento(Memento *memento);
    void show();
};

std::string Originator::getState()
{
    return state;
}

void Originator::setState(std::string _state)
{
    state = _state;
}

Memento *Originator::createMemento()
{
    return new Memento(state);
}

void Originator::setMemento(Memento *memento)
{
    state = memento->getState();
}

void Originator::show()
{
    std::cout << "State = " << state << std::endl;
}

#endif /*_ORIGINATOR_*/