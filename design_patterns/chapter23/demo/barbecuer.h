#ifndef BARBECUER_H
#define BARBECUER_H

#include <iostream>

class Barbecuer
{
public:
    Barbecuer(){};
    ~Barbecuer(){};
    void bakeMutton();
    void bakeChickenWing();
};

void Barbecuer::bakeMutton()
{
    std::cout << "烤羊肉串！" << std::endl;
}

void Barbecuer::bakeChickenWing()
{
    std::cout << "烤鸡翅！" << std::endl;
}

#endif /*BARBECUER_H*/