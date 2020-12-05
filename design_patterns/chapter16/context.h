#ifndef _CONTEXT_
#define _CONTEXT_

class State;

class Context
{
private:
    State *state;

public:
    Context(State *_state) : state(_state){};
    ~Context(){};
    State *getState();
    void setState(State *_state);
    void request();
};

#endif /*_CONTETXT_*/