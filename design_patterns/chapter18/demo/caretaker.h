#ifndef _CARETAKER_
#define _CARETAKER_

#include "memento.h"

class Caretaker
{
private:
    Memento *memento;

public:
    Caretaker(){};
    ~Caretaker(){};
    Memento *getMemento();
    void setMemento(Memento *_memento);
};

Memento *Caretaker::getMemento()
{
    return memento;
}

void Caretaker::setMemento(Memento *_memento)
{
    memento = _memento;
}

#endif /*_CARETAKER_*/