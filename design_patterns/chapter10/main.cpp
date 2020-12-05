#include <iostream>

#include "abstractClass.h"

using namespace std;

int main()
{
    AbstractClass *c;

    c = new ConcreteClassA();
    c->TemplateMethod();

    c = new ConcreteClassB();
    c->TemplateMethod();

    return 0;
}