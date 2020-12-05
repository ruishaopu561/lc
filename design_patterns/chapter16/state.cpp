#include "state.h"
#include "context.h"

void ConcreteStateA::handle(Context *context)
{
    context->setState(new ConcreteStateB(name + 1));
}

void ConcreteStateB::handle(Context *context)
{
    context->setState(new ConcreteStateA(name + 1));
}