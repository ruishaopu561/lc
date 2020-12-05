#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Action;

class Person
{
public:
    Person(){};
    ~Person(){};
    virtual void accept(Action *visitor) = 0;
};

class Man : public Person
{
public:
    Man(){};
    ~Man(){};
    void accept(Action *visitor);
};

class Woman : public Person
{
public:
    Woman(){};
    ~Woman(){};
    void accept(Action *visitor);
};

#endif /*PERSON_H*/
