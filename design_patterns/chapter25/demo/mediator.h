#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <string>

class Colleague;
class ConcreteColleague1;
class ConcreteColleague2;

class Mediator
{
public:
    Mediator(){};
    ~Mediator(){};
    virtual void send(std::string message, Colleague *colleague) = 0;
};

class ConcreteMediator : public Mediator
{
private:
    ConcreteColleague1 *colleague1;
    ConcreteColleague2 *colleague2;

public:
    ConcreteMediator(){};
    ~ConcreteMediator(){};
    void setColleague1(ConcreteColleague1 *colleague);
    void setColleague2(ConcreteColleague2 *colleague);
    void send(std::string message, Colleague *colleague);
};

#endif /*MEDIATOR_H*/