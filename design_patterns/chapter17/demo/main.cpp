#include <iostream>

#include "target.h"
#include "adaptee.h"

using namespace std;

int main()
{
    Target *target = new Adapter();
    target->request();

    return 0;
}