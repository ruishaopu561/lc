#ifndef COUNTRY_H
#define COUNTRY_H

#include <iostream>
#include <string>

class UnitedNations;

class Country
{
private:
    UnitedNations *mediator;

public:
    Country(UnitedNations *_mediator) : mediator(_mediator){};
    ~Country(){};
    UnitedNations *getMediator();
};

class USA : public Country
{
public:
    USA(UnitedNations *_mediator) : Country(_mediator){};
    ~USA(){};
    void declare(std::string message);
    void getMessage(std::string message);
};

class Irap : public Country
{
public:
    Irap(UnitedNations *_mediator) : Country(_mediator){};
    ~Irap(){};
    void declare(std::string message);
    void getMessage(std::string message);
};

#endif /*COUNTRY_H*/