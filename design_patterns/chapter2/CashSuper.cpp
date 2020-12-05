#include "CashSuper.h"

double CashNormal::acceptCash(double money)
{
    return money;
}

double CashRebate::acceptCash(double money)
{
    return money * moneyRebate;
}

double CashReturn::acceptCash(double money)
{
    double result = money;
    if(money >= moneyCondition){
        result = money - money / moneyCondition * moneyReturn;
    }

    return result;
}
