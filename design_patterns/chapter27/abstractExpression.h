#ifndef ABSTRACTEXPRESSION_H
#define ABSTRACTEXPRESSION_H

#include <iostream>

#include "context.h"

class AbstractExpression
{
public:
    AbstractExpression(){};
    ~AbstractExpression(){};
    virtual void interpret(Context *context) = 0;
};

class TerminalExpression : public AbstractExpression
{
public:
    TerminalExpression(){};
    ~TerminalExpression(){};
    void interpret(Context *context);
};

void TerminalExpression::interpret(Context *context)
{
    std::cout << "终端解释器" << std::endl;
}

class NonterminalExpression : public AbstractExpression
{
public:
    NonterminalExpression(){};
    ~NonterminalExpression(){};
    void interpret(Context *context);
};

void NonterminalExpression::interpret(Context *context)
{
    std::cout << "非终端解释器" << std::endl;
}

#endif /*ABSTRACTEXPRESSION_H*/