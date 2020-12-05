#include <iostream>

#include "facade.h"

using namespace std;

int main()
{
    Facade *facade = new Facade();

    facade->methodA();
    facade->methodB();

    return 0;
}