#include <iostream>

#include "barbecuer.h"

using namespace std;

int main()
{
    Barbecuer *boy = new Barbecuer();

    boy->bakeMutton();
    boy->bakeMutton();
    boy->bakeMutton();
    boy->bakeChickenWing();
    boy->bakeMutton();
    boy->bakeMutton();
    boy->bakeChickenWing();

    return 0;
}