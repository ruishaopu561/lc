#include "unitedNations.h"
#include "country.h"

void UnitedNationsSecurityCouncil::setColleague1(USA *colleague)
{
    colleague1 = colleague;
}

void UnitedNationsSecurityCouncil::setColleague2(Irap *colleague)
{
    colleague2 = colleague;
}

void UnitedNationsSecurityCouncil::declare(std::string message, Country *country)
{
    if (colleague1 == country)
    {
        colleague2->getMessage(message);
    }
    else
    {
        colleague1->getMessage(message);
    }
}
