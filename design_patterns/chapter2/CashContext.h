#ifndef _CASHCONTEXT_
#define _CASHCONTEXT_

#include "cashSuper.h"

class CashContext
{
private:
    CashSuper *cashSuper = NULL;
public:
    CashContext(int type);
    ~CashContext();
    double getResult(double money);
};

// 结合了策略模式和简单工厂模式
// 简单工厂模式体现在CashContext类的构造函数里，参数是子类的类型，根据类型选择创建不同的子
// 类实例，从而简化客户端(main.cpp)的代码结构，这正是一个简单工厂最好的体现；
CashContext::CashContext(int type)
{
    switch (type)
    {
    case 1:
        cashSuper = new CashNormal();
        break;
    case 2:
        cashSuper = new CashRebate(0.8);
        break;
    case 3:
        cashSuper = new CashReturn(300, 100);
        break;
    }
}

CashContext::~CashContext()
{
    delete cashSuper;
}

double CashContext::getResult(double money)
{
    return cashSuper->acceptCash(money);
}

#endif /*_CASHCONTEXT*/