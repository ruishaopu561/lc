#ifndef _CASHSUPER_
#define _CASHSUPER_

// 这里主要体现了策略模式，对不同类型的算法进行封装并实现多态和继承；
// 策略模式主要就是针对各种本质上重复、提供的目标接口统一，但具体又各不相同的
// 算法的具体实现。
// 比如这里，找钱主要是三种方式：不打折、打折、满减，而对于打折和满减，由于具体
// 参数可变，只利用单纯的简单工厂需要实现n多个类，因此需要先找钱策略本身抽象，然
// 后再进行实现。
class CashSuper
{
public:
    CashSuper();
    ~CashSuper();
    double acceptCash(double money) = 0;
};

class CashNormal:public CashSuper
{
public:
    CashNormal(){};
    ~CashNormal(){};
    double acceptCash(double money);
};

class CashRebate:public CashSuper
{
private:
    double moneyRebate;
public:
    CashRebate(double mr):moneyRebate(mr){};
    ~CashRebate();
    double acceptCash(double money);
};

class CashReturn:public CashSuper
{
private:
    double moneyCondition = 0;
    double moneyReturn = 0;
public:
    CashReturn(double mc, double mr):moneyCondition(mc), moneyReturn(mr){};
    ~CashReturn();
    double acceptCash(double money);
};

#endif /*_CASHSUPER*/