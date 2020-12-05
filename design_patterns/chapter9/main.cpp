#include <iostream>

#include "resume.h"
#include "prototype.h"

using namespace std;

void prototype_display()
{
    ConcretePrototype1 *p1 = new ConcretePrototype1("I");
    ConcretePrototype1 *c1 = (ConcretePrototype1 *)p1->clone();

    cout << "Cloned: {0} " << c1->id << endl;
}

void resume_display()
{
    Resume *a = new Resume("BigBird1");
    a->setPersonalInfo("male", "29");
    a->setWorkExperience("2018-2020", "xx company");

    Resume *b = (Resume*)a->clone();
    b->setWorkExperience("2019-2021", "yy organization");

    Resume *c = (Resume*)a->clone();
    c->setWorkExperience("2014-2017", "zz organization");

    a->display();
    b->display();
    c->display();

    cout << endl;
}

int main()
{
    resume_display();
    prototype_display();
    return 0;
}