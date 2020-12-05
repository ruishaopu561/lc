#include "observer.h"
#include "secretary.h"

#include <iostream>
#include <vector>

void StockObserver::update()
{
    std::cout << sub->getState() << " " << name << " close the stock, work!" << std::endl;
}

void NBAObserver::update()
{
    std::cout << sub->getState() << " " << name << " close the NBA, work!" << std::endl;
}