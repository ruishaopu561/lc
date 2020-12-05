#include <iostream>

#include "leifeng.h"

using namespace std;

int main()
{
    IFactory *factory = new UndergraduateFactory();
    LeiFeng *xueleifeng = factory->createLeiFeng();

    xueleifeng->buyRice();
    xueleifeng->sweep();
    xueleifeng->wash();

    return 0;
}   