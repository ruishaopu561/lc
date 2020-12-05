#include <iostream>

#include "waiter.h"
#include "command.h"
#include "barbecuer.h"

using namespace std;

int main()
{
    Barbecuer *boy = new Barbecuer();
    Command *BakeMuttonCommand1 = new BakeMuttonCommand(boy);
    Command *BakeMuttonCommand2 = new BakeMuttonCommand(boy);
    Command *BakeChickenWingCommand1 = new BakeChickenWingCommand(boy);

    Waiter *girl = new Waiter();
    girl->setOrder(BakeMuttonCommand1);
    girl->setOrder(BakeMuttonCommand2);
    girl->setOrder(BakeChickenWingCommand1);

    girl->notify();

    return 0;
}