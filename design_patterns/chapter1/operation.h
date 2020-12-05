#ifndef _OPERATION_
#define _OPERATION_

class Operation
{
private:
    double left;
    double right;

public:
    Operation(double l, double r) : left(l), right(r){};
    ~Operation(){};
    double getLeft();
    double getRight();
    void setLeft(double value);
    void setRight(double value);
    virtual double calculate() = 0;
};

class OperationAdd : public Operation
{
public:
    OperationAdd() : Operation(0, 0){};
    OperationAdd(double l, double r) : Operation(l, r){};
    ~OperationAdd(){};
    double calculate();
};

class OperationSub : public Operation
{
public:
    OperationSub() : Operation(0, 0){};
    OperationSub(double l, double r) : Operation(l, r){};
    ~OperationSub(){};
    double calculate();
};

class OperationMul : public Operation
{
public:
    OperationMul() : Operation(0, 0){};
    OperationMul(double l, double r) : Operation(l, r){};
    ~OperationMul(){};
    double calculate();
};

class OperationDiv : public Operation
{
public:
    OperationDiv() : Operation(0, 0){};
    OperationDiv(double l, double r) : Operation(l, r){};
    ~OperationDiv(){};
    double calculate();
};

#endif /*_OPERATION_*/