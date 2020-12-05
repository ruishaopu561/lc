#include <iostream>

#include "pursuit.h"

using namespace std;

int main()
{
    SchoolGirl *jiaojiao = new SchoolGirl();
    jiaojiao->setName("lijiaojiao");

    Pursuit *zhuojiayi = new Pursuit(jiaojiao);

    zhuojiayi->giveDolls();
    zhuojiayi->giveFlowers();
    zhuojiayi->giveChocolate();

    return 0;
}