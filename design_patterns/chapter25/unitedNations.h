#ifndef UNITEDNATIONS_H
#define UNITEDNATIONS_H

#include <string>

class Country;
class USA;
class Irap;

class UnitedNations
{
private:
public:
    UnitedNations(){};
    ~UnitedNations(){};
    virtual void declare(std::string message, Country *country) = 0;
};

class UnitedNationsSecurityCouncil : public UnitedNations
{
private:
    USA *colleague1;
    Irap *colleague2;

public:
    UnitedNationsSecurityCouncil(){};
    ~UnitedNationsSecurityCouncil(){};
    void setColleague1(USA *colleague);
    void setColleague2(Irap *colleague);
    void declare(std::string message, Country *country);
};

#endif /*UNITEDNATIONS_H*/