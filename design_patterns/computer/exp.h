#ifndef EXP_H
#define EXP_H

#include <iostream>
#include <string>
#include <map>
#include "tokenscanner.h"

class EvaluationContext;

enum ExpressionType
{
    CONSTANT,
    IDENTIFIER,
    COMPOUND,
    FACT,
};

class Expression
{
public:
    Expression();
    ~Expression();
    virtual int eval(EvaluationContext *context) = 0;
    virtual std::string toString() = 0;
    virtual ExpressionType getType() = 0;

    virtual int getConstantValue();
    virtual std::string getIdentifierName();
    virtual std::string getOperator();
    virtual Expression *getLHS();
    virtual Expression *getRHS();
};

class ConstantExp : public Expression
{
public:
    ConstantExp(int _value);
    ~ConstantExp();

    virtual int eval(EvaluationContext *context);
    virtual std::string toString();
    virtual ExpressionType getType();
    virtual int getConstantValue();

private:
    int value;
};

class IdentifierExp : public Expression
{
public:
    IdentifierExp(std::string _name);
    ~IdentifierExp();

    virtual int eval(EvaluationContext *context);
    virtual std::string toString();
    virtual ExpressionType getType();
    virtual std::string getIdentifierName();

private:
    std::string name;
};

class CompoundExp : public Expression
{
public:
    CompoundExp(std::string _op, Expression *_lhs, Expression *_rhs);
    virtual ~CompoundExp();
    virtual int eval(EvaluationContext *context);
    virtual std::string toString();
    virtual ExpressionType getType();
    virtual std::string getOperator();
    virtual Expression *getLHS();
    virtual Expression *getRHS();

private:
    std::string op;
    Expression *lhs, *rhs;
};

class FactExp:public Expression
{
public:
    FactExp(std::string _op, Expression *_lhs);
    ~FactExp();
    virtual int eval(EvaluationContext *context);
    virtual std::string toString();
    virtual ExpressionType getType();
    virtual std::string getOperator();
    virtual Expression *getLHS();
private:
    Expression* lhs;
    std::string op;
};

class EvaluationContext
{
private:
public:
    EvaluationContext();
    ~EvaluationContext();

    void setValue(std::string var, int value);
    int getValue(std::string var);
    bool isDefined(std::string var);

private:
    std::map<std::string, int> symbolTable;
};

#endif /*EXP_H*/