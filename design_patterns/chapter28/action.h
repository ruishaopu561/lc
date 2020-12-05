#ifndef ACTION_H
#define ACTION_H

class Person;
class Man;
class Woman;

class Action
{
public:
    Action(){};
    ~Action(){};
    virtual void getManConclusion(Man *man) = 0;
    virtual void getWomanConclusion(Woman *woman) = 0;
};

class Success : public Action
{
public:
    Success(){};
    ~Success(){};
    void getManConclusion(Man *man);
    void getWomanConclusion(Woman *woman);
};

class Failing : public Action
{
public:
    Failing(){};
    ~Failing(){};
    void getManConclusion(Man *man);
    void getWomanConclusion(Woman *woman);
};

class Amativeness : public Action
{
public:
    Amativeness(){};
    ~Amativeness(){};
    void getManConclusion(Man *man);
    void getWomanConclusion(Woman *woman);
};

#endif /*ACTION_H*/