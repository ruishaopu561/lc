#include <iostream>

#include "gameRole.h"

using namespace std;

int main()
{
    GameRole *lixiaoyao = new GameRole();
    lixiaoyao->initState();
    lixiaoyao->stateDisplay();

    GameRole *backup = new GameRole();
    backup->setVit(lixiaoyao->getVit()); 
    backup->setAtk(lixiaoyao->getAtk());
    backup->setDef(lixiaoyao->getDef());

    lixiaoyao->fight();
    lixiaoyao->stateDisplay();

    lixiaoyao->setVit(backup->getVit());
    lixiaoyao->setAtk(backup->getAtk());
    lixiaoyao->setDef(backup->getDef());

    lixiaoyao->stateDisplay();

    return 0;
}