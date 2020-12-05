#ifndef _OPERATIONFACTORY_
#define _OPERATIONFACTORY_

#include "operation.h"

class OperationFactory
{
private:
    Operation *oper;

public:
    OperationFactory(){};
    ~OperationFactory() { delete oper; };
    Operation *createOperation(char op);
};

Operation *OperationFactory::createOperation(char op)
{
    switch (op)
    {
    case '+':
        oper = new OperationAdd();
        break;
    case '-':
        oper = new OperationSub();
        break;
    case '*':
        oper = new OperationMul();
        break;
    case '/':
        oper = new OperationDiv();
        break;
    default:
        oper = NULL;
        break;
    }

    return oper;
}

#endif /*_OPERATIONFACTORY_*/