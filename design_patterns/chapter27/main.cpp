#include <vector>

#include "context.h"
#include "abstractExpression.h"

using namespace std;

int main()
{
    vector<AbstractExpression *> list;
    Context *context = new Context();
    list.push_back(new TerminalExpression());
    list.push_back(new NonterminalExpression());
    list.push_back(new TerminalExpression());
    list.push_back(new NonterminalExpression());

    for (int i = 0; i < list.size(); i++)
    {
        list[i]->interpret(context);
    }

    return 0;
}