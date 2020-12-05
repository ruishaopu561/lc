#ifndef COLLEAGUE_H
#define COLLEAGUE_H

#include <string>

class Mediator;

class Colleague
{
private:
    Mediator *mediator;

public:
    Colleague(Mediator *_mediator) : mediator(_mediator){};
    ~Colleague(){};
    Mediator *getMediator();
};

class ConcreteColleague1 : public Colleague
{
public:
    ConcreteColleague1(Mediator *mediator) : Colleague(mediator){};
    ~ConcreteColleague1(){};
    void send(std::string message);
    void notify(std::string message);
};

class ConcreteColleague2 : public Colleague
{
public:
    ConcreteColleague2(Mediator *mediator) : Colleague(mediator){};
    ~ConcreteColleague2(){};
    void send(std::string message);
    void notify(std::string message);
};

#endif /*COLLEAGUE_H*/