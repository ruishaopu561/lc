#ifndef _STRATEGY_
#define _STRATEGY_

class Strategy
{
public:
    Strategy();
    ~Strategy();
    virtual void AlgorithmInterface() = 0;
};

class ConcreteStrategyA : public Strategy
{
public:
    ConcreteStrategyA(){};
    ~ConcreteStrategyA(){};
    void AlgorithmInterface();
};

void ConcreteStrategyA::AlgorithmInterface()
{
}

class ConcreteStrategyB : public Strategy
{
public:
    ConcreteStrategyB();
    ~ConcreteStrategyB();
    void AlgorithmInterface();
};

void ConcreteStrategyB::AlgorithmInterface()
{
}

class ConcreteStrategyC : public Strategy
{
public:
    ConcreteStrategyC();
    ~ConcreteStrategyC();
    void AlgorithmInterface();
};

void ConcreteStrategyC::AlgorithmInterface()
{
}

#endif /*_STRATEGY_*/