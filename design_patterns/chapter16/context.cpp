#include "context.h"
#include "state.h"

#include <iostream>

State *Context::getState()
{
    return state;
}

void Context::setState(State *_state)
{
    state = _state;
    std::cout << "current state: " << state->name << std::endl;
}

void Context::request()
{
    state->handle(this);
}