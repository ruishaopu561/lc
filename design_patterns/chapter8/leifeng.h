#ifndef _LEIFENG_
#define _LEIFENG_

#include <iostream>

class LeiFeng
{
public:
    LeiFeng(){};
    ~LeiFeng(){};
    void sweep();
    void wash();
    void buyRice();
};

void LeiFeng::sweep()
{
    std::cout << "sweep" << std::endl;
}

void LeiFeng::wash()
{
    std::cout << "wash" << std::endl;
}

void LeiFeng::buyRice()
{
    std::cout << "buy rice" << std::endl;
}

class Undergraduate : public LeiFeng
{
public:
    Undergraduate(){};
    ~Undergraduate(){};
};

class Volunteer : public LeiFeng
{
public:
    Volunteer(){};
    ~Volunteer(){};
};

// 创建工厂
class IFactory
{
public:
    IFactory();
    ~IFactory();
    virtual LeiFeng *createLeiFeng() = 0;
};

class UndergraduateFactory : public IFactory
{
public:
    UndergraduateFactory(){};
    ~UndergraduateFactory(){};
    LeiFeng *createLeiFeng();
};

LeiFeng *UndergraduateFactory::createLeiFeng()
{
    return new Undergraduate();
}

class VolunteerFactory : public IFactory
{
public:
    VolunteerFactory(){};
    ~VolunteerFactory(){};
    LeiFeng *createLeiFeng();
};

LeiFeng *VolunteerFactory::createLeiFeng()
{
    return new Volunteer();
}

#endif /*_LEIFENG_*/