#include <iostream>

#include "handsetSoft.h"
#include "handsetBrand.h"

using namespace std;

int main()
{
    HandsetBrand *ab;
    ab = new HandsetBrandN();

    ab->setHandsetSoft(new HandsetGame());
    ab->run();

    ab->setHandsetSoft(new HandsetAddressList());
    ab->run();

    ab = new HandsetBrandM();

    ab->setHandsetSoft(new HandsetGame());
    ab->run();

    ab->setHandsetSoft(new HandsetAddressList());
    ab->run();

    return 0;
}