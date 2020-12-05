#include <iostream>

#include "component.h"

using namespace std;

int main()
{
    // 可以类比到穿衣搭配问题
    ConcreteComponent *c = new ConcreteComponent();
    ConcreteDecoratorA *d1 = new ConcreteDecoratorA();
    ConcreteDecoratorB *d2 = new ConcreteDecoratorB();

    d1->setComponent(c);
    d2->setComponent(d1);
    d2->operation();

    return 0;
}