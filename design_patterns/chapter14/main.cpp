#include <iostream>

#include "observer.h"
#include "secretary.h"

using namespace std;

int main()
{
    Boss *huhansan = new Boss();

    StockObserver *tongshi1 = new StockObserver("weiguancha", huhansan);
    NBAObserver *tongshi2 = new NBAObserver("yiguancha", huhansan);

    huhansan->attach(tongshi1);
    huhansan->attach(tongshi2);
    huhansan->detach(tongshi1);
    huhansan->setState("Huhansan is back,");

    huhansan->notify();

    return 0;
}