#include "mediator.h"
#include "colleague.h"

void ConcreteMediator::setColleague1(ConcreteColleague1 *colleague)
{
    colleague1 = colleague;
}

void ConcreteMediator::setColleague2(ConcreteColleague2 *colleague)
{
    colleague2 = (ConcreteColleague2 *)colleague;
}

void ConcreteMediator::send(std::string message, Colleague *colleague)
{
    if (colleague1 == colleague)
    {
        colleague2->notify(message);
    }
    else
    {
        colleague1->notify(message);
    }
}
