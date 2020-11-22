#include <string>
#include "exp.h"

Expression::Expression() {}

Expression::~Expression() {}

int Expression::getConstantValue()
{
    std::cout << "getConstantValue: Illegal expression type" << std::endl;
    return 0;
}

std::string Expression::getIdentifierName()
{
    std::cout << "getIdentifierName: Illegal expression type" << std::endl;
    return "";
}

std::string Expression::getOperator()
{
    std::cout << "getOperator: Illegal expression type" << std::endl;
    return "";
}

Expression *Expression::getLHS()
{
    std::cout << "getLHS: Illegal expression type" << std::endl;
    return NULL;
}

Expression *Expression::getRHS()
{
    std::cout << "getRHS: Illegal expression type" << std::endl;
    return NULL;
}

// -----------------------------------------------------

ConstantExp::ConstantExp(int _value)
{
    value = _value;
}

int ConstantExp::eval(EvaluationContext *context)
{
    return value;
}

std::string ConstantExp::toString()
{
    return std::to_string(value);
}

ExpressionType ConstantExp::getType()
{
    return CONSTANT;
}

int ConstantExp::getConstantValue()
{
    return value;
}

// -----------------------------------------------------

IdentifierExp::IdentifierExp(std::string _name)
{
    name = _name;
}

int IdentifierExp::eval(EvaluationContext *context)
{
    if (!context->isDefined(name))
    {
        std::cout << name + " is undefined" << std::endl;
    }
    return context->getValue(name);
}

std::string IdentifierExp::toString()
{
    return name;
}

ExpressionType IdentifierExp::getType()
{
    return IDENTIFIER;
}

std::string IdentifierExp::getIdentifierName()
{
    return name;
}

// -----------------------------------------------------

CompoundExp::CompoundExp(std::string _op, Expression *_lhs, Expression *_rhs)
{
    op = _op;
    lhs = _lhs;
    rhs = _rhs;
}

CompoundExp::~CompoundExp()
{
    delete lhs;
    delete rhs;
}

int CompoundExp::eval(EvaluationContext *context)
{
    int right = rhs->eval(context);
    if (op == "=")
    {
        context->setValue(lhs->getIdentifierName(), right);
        return right;
    }
    int left = lhs->eval(context);
    if (op == "+")
    {
        return left + right;
    }
    if (op == "-")
    {
        return left - right;
    }
    if (op == "*")
    {
        return left * right;
    }
    if (op == "/")
    {
        if (right == 0)
        {
            std::cout << "Division by 0" << std::endl;
        }
        else
        {
            return left / right;
        }
    }
    std::cout << "Illegal operator in expression" << std::endl;
    return 0;
}

std::string CompoundExp::toString()
{
    return '(' + lhs->toString() + ' ' + op + ' ' + rhs->toString() + ')';
}

ExpressionType CompoundExp::getType()
{
    return COMPOUND;
}

std::string CompoundExp::getOperator()
{
    return op;
}

Expression *CompoundExp::getLHS()
{
    return lhs;
}

Expression *CompoundExp::getRHS()
{
    return rhs;
}

// -----------------------------------------------------------

EvaluationContext::EvaluationContext() {}

EvaluationContext::~EvaluationContext() {}

void EvaluationContext::setValue(std::string var, int value)
{
    symbolTable[var] = value;
}

int EvaluationContext::getValue(std::string var)
{
    return symbolTable[var];
}

bool EvaluationContext::isDefined(std::string var)
{
    return symbolTable.find(var) != symbolTable.end();
}