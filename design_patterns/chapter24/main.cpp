#include <iostream>

#include "request.h"
#include "manager.h"

using namespace std;

int main()
{
    Manager *jinli = new CommonManager("金利");
    Manager *zongjian = new Majordomo("总检");
    Manager *zongjinli = new GeneralManager("钟经理");
    jinli->setSuperior(zongjian);
    zongjian->setSuperior(zongjinli);

    Request *request = new Request();
    request->setRequestType("请假");
    request->setRequestContent("小菜请假");
    request->setNumber(1);
    jinli->handleRequest(request);
    
    Request *request2 = new Request();
    request2->setRequestType("请假");
    request2->setRequestContent("小菜请假");
    request2->setNumber(4);
    jinli->handleRequest(request2);

    Request *request3 = new Request();
    request3->setRequestType("加薪");
    request3->setRequestContent("小菜请求加薪");
    request3->setNumber(500);
    jinli->handleRequest(request3);

    Request *request4 = new Request();
    request4->setRequestType("加薪");
    request4->setRequestContent("小菜请求加薪");
    request4->setNumber(1000);
    jinli->handleRequest(request4);

    return 0;
}