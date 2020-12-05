#ifndef _GAMEROLE_
#define _GAMEROLE_

#include <iostream>

class GameRole
{
private:
    int vit;
    int atk;
    int def;

public:
    GameRole(){};
    ~GameRole(){};
    int getVit();
    void setVit(int _vit);
    int getAtk();
    void setAtk(int _atk);
    int getDef();
    void setDef(int _def);
    void initState();
    void stateDisplay();
    void fight();
};

int GameRole::getVit()
{
    return vit;
}

void GameRole::setVit(int _vit)
{
    vit = _vit;
}

int GameRole::getAtk()
{
    return atk;
}

void GameRole::setAtk(int _atk)
{
    atk = _atk;
}

int GameRole::getDef()
{
    return def;
}

void GameRole::setDef(int _def)
{
    def = _def;
}

void GameRole::initState()
{
    vit = 100;
    atk = 100;
    def = 100;
}

void GameRole::stateDisplay()
{
    std::cout << "Role current state:" << std::endl;
    std::cout << "Vitality: " << vit << std::endl;
    std::cout << "Attack: " << atk << std::endl;
    std::cout << "Deffence: " << def << std::endl;
    std::cout << std::endl;
}

void GameRole::fight()
{
    vit = 0;
    atk = 0;
    def = 0;
}

#endif /*_GAMEROLE_*/