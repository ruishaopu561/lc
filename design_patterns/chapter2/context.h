#ifndef _CONTEXT_
#define _CONTEXT_

#include "strategy.h"

class Context
{
private:
    Strategy *strategy;
public:
    Context(Strategy *s);
    ~Context();
    void contextInterface();
};

Context::Context(Strategy *s)
{
    strategy = s;
}

Context::~Context()
{
    delete strategy;
}

void Context::contextInterface()
{
    strategy->AlgorithmInterface();
}

#endif /*_CONTEXT_*/