#include <iostream>
#include <string>

#include "exp.h"
#include "parser.h"
#include "tokenscanner.h"

using namespace std;

int main()
{
    string str = "";
    TokenScanner *scanner = new TokenScanner(str);
    EvaluationContext *context = new EvaluationContext();

    while (true)
    {
        cout << "> ";
        cin >> str;
        scanner->setInput(str);

        Expression *exp = parseExp(scanner);
        cout << exp->eval(context) << endl;
    }
    return 0;
}