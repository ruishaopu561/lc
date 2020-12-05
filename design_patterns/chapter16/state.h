#ifndef _STATE_
#define _STATE_

class Context;

class State
{
public:
    int name;
    State(int _name) : name(_name){};
    ~State(){};
    virtual void handle(Context *context) = 0;
};

class ConcreteStateA : public State
{
public:
    ConcreteStateA(int _name) : State(_name){};
    ~ConcreteStateA(){};
    void handle(Context *context);
};

class ConcreteStateB : public State
{
public:
    ConcreteStateB(int _name) : State(_name){};
    ~ConcreteStateB(){};
    void handle(Context *context);
};

#endif /*_STATE_*/