#include <iostream>

#include "abstraction.h"
#include "implementor.h"

using namespace std;

int main()
{
    Abstraction *ab = new RefinedAbstraction();

    ab->setImplementor(new ConcreteImplementorA());
    ab->operation();

    ab->setImplementor(new ConcreteImplementorB());
    ab->operation();

    return 0;
}