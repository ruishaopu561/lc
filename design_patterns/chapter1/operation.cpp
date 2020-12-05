#include "operation.h"

double Operation::getLeft()
{
    return left;
}

double Operation::getRight()
{
    return right;
}

void Operation::setLeft(double value)
{
    left = value;
}

void Operation::setRight(double value)
{
    right = value;
}

double OperationAdd::calculate()
{
    return getLeft() + getRight();
}

double OperationSub::calculate()
{
    return getLeft() - getRight();
}

double OperationMul::calculate()
{
    return getLeft() * getRight();
}

double OperationDiv::calculate()
{
    return getRight() == 0 ? 0 : getLeft() / getRight();
}