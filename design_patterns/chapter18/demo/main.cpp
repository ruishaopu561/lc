#include <iostream>

#include "originator.h"
#include "memento.h"
#include "caretaker.h"

using namespace std;

int main()
{
    Originator *o = new Originator();
    o->setState("On");
    o->show();

    Caretaker *c = new Caretaker();
    c->setMemento(o->createMemento());

    o->setState("Off");
    o->show();

    o->setMemento(c->getMemento());
    o->show();

    return 0;
}