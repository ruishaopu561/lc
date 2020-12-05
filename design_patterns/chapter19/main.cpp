#include <iostream>

#include "company.h"

using namespace std;

int main()
{
    ConcreteCompany *root = new ConcreteCompany("北京总公司");
    root->add(new HRDepartment("总公司人力资源部"));
    root->add(new FinanceDepartment("总公司财务部"));

    ConcreteCompany *comp = new ConcreteCompany("上海华东分公司");
    comp->add(new HRDepartment("华东分公司人力资源部"));
    comp->add(new FinanceDepartment("华东分公司财务部"));
    root->add(comp);

    ConcreteCompany *comp1 = new ConcreteCompany("南京办事处");
    comp->add(new HRDepartment("南京办事处人力资源部"));
    comp->add(new FinanceDepartment("南京办事处财务部"));
    root->add(comp1);

    ConcreteCompany *comp2 = new ConcreteCompany("杭州办事处");
    comp->add(new HRDepartment("杭州办事处人力资源部"));
    comp->add(new FinanceDepartment("杭州办事处财务部"));
    root->add(comp2);

    cout << "\n 结构图：" << endl;
    root->display(1);

    cout << "\n 职责：" << endl;
    root->lineOfDuty();

    return 0;
}