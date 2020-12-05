#include <iostream>
#include <string>

#include "operation.h"
#include "operationFactory.h"

using namespace std;

int main()
{
    double left = 0, right = 0;
    char op;
    OperationFactory *operationFactory = new OperationFactory();
    Operation *oper = NULL;
    while (true)
    {
        cout << "Please enter two numbers and one operator: " << endl;
        cin >> left >> right >> op;

        if ((oper = operationFactory->createOperation(op)) == NULL)
        {
            cout << "Please enter an operator as the third parameter!" << endl;
            continue;
        }

        oper->setLeft(left);
        oper->setRight(right);

        cout << "The result is " << oper->calculate() << endl;
    }
}