#include <iostream>
#include <vector>

#include "handler.h"
#include "request.h"

using namespace std;

int main()
{
    Handler *h1 = new ConcreteHandler1("经理");
    Handler *h2 = new ConcreteHandler2("总监");
    Handler *h3 = new ConcreteHandler3("总经理");
    h1->setSuccessor(h2);
    h2->setSuccessor(h3);

    vector<int> requests = {2, 5, 14, 22, 18, 3, 27, 20};
    for (int i = 0; i < requests.size(); i++)
    {
        h1->handleRequest(requests[i]);
    }

    return 0;
}