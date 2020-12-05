#include <iostream>

#include "cashSuper.h"
#include "CashContext.h"

using namespace std;

int main()
{
    double money = 0, total;
    int strategy = 1;
    CashContext *cc;

    while(cin >> money >> strategy)
    {
        cc = NULL;
        if((cc = new CashContext(strategy)) != NULL){
            total += cc->getResult(money);
        }
    }
    return 0;
}