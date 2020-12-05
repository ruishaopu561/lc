#ifndef _GIVEGIFT_
#define _GIVEGIFT_

#include <iostream>
#include <string>

class SchoolGirl
{
private:
    std::string name;

public:
    SchoolGirl(){};
    ~SchoolGirl(){};
    std::string getName();
    void setName(std::string n);
};

std::string SchoolGirl::getName()
{
    return name;
}

void SchoolGirl::setName(std::string n)
{
    name = n;
}

class GiveGift
{
public:
    GiveGift();
    ~GiveGift();
    virtual void giveDolls() = 0;
    virtual void giveFlowers() = 0;
    virtual void giveChocolate() = 0;
};

class Pursuit : public GiveGift
{
public:
    SchoolGirl *mm;

    Pursuit(SchoolGirl *m) : mm(m){};
    ~Pursuit(){};
    void giveDolls();
    void giveFlowers();
    void giveChocolate();
};

void Pursuit::giveDolls()
{
    std::cout << mm->getName() << ", give you dolls" << std::endl;
}

void Pursuit::giveFlowers()
{
    std::cout << mm->getName() << ", give you flowers" << std::endl;
}

void Pursuit::giveChocolate()
{
    std::cout << mm->getName() << ", give you chocolate" << std::endl;
}

class Proxy : public GiveGift
{
public:
    Pursuit *gg;

    // Proxy(){};
    Proxy(SchoolGirl *mm);
    ~Proxy(){};
    void giveDolls();
    void giveFlowers();
    void giveChocolate();
};

Proxy::Proxy(SchoolGirl *mm)
{
    gg = new Pursuit(mm);
}

void Proxy::giveDolls()
{
    gg->giveDolls();
}

void Proxy::giveFlowers()
{
    gg->giveFlowers();
}

void Proxy::giveChocolate()
{
    gg->giveChocolate();
}

#endif /*_GIVEGIFT*/