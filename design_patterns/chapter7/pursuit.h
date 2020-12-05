#ifndef _PURSUIT_
#define _PURSUIT_

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

class Pursuit
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

#endif /*_PURSUIT_*/