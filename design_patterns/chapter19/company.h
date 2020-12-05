#ifndef _COMPANY_
#define _COMPANY_

#include <iostream>
#include <string>
#include <vector>

class Company
{
public:
    std::string name;

    Company(std::string _name) : name(_name){};
    ~Company(){};
    virtual void add(Company *c) = 0;
    virtual void remove(Company *c) = 0;
    virtual void display(int depth) = 0;
    virtual void lineOfDuty() = 0; // 履行职责
};

class ConcreteCompany : public Company
{
private:
    std::vector<Company *> children;

public:
    ConcreteCompany(std::string _name) : Company(_name){};
    ~ConcreteCompany(){};
    void add(Company *c);
    void remove(Company *c);
    void display(int depth);
    void lineOfDuty(); // 履行职责
};

void ConcreteCompany::add(Company *c)
{
    children.push_back(c);
}

void ConcreteCompany::remove(Company *c)
{
    for (int i = 0; i < children.size(); i++)
    {
        if (children[i] == c)
        {
            children.erase(children.begin() + i);
            return;
        }
    }
}

void ConcreteCompany::display(int depth)
{
    std::cout << "-" << depth << " " << name << std::endl;
    for (int i = 0; i < children.size(); i++)
    {
        children[i]->display(depth + 1);
    }
}

void ConcreteCompany::lineOfDuty()
{
    for (int i = 0; i < children.size(); i++)
    {
        children[i]->lineOfDuty();
    }
}

class HRDepartment : public Company
{
public:
    HRDepartment(std::string _name) : Company(_name){};
    ~HRDepartment(){};
    void add(Company *c){};
    void remove(Company *c){};
    void display(int depth);
    void lineOfDuty(); // 履行职责
};

void HRDepartment::display(int depth)
{
    std::cout << "-" << depth << " " << name << std::endl;
}

void HRDepartment::lineOfDuty()
{
    std::cout << name << "recruit employers management" << std::endl;
}

class FinanceDepartment : public Company
{
public:
    FinanceDepartment(std::string _name) : Company(_name){};
    ~FinanceDepartment(){};
    void add(Company *c){};
    void remove(Company *c){};
    void display(int depth);
    void lineOfDuty(); // 履行职责
};

void FinanceDepartment::display(int depth)
{
    std::cout << "-" << depth << " " << name << std::endl;
}

void FinanceDepartment::lineOfDuty()
{
    std::cout << name << "company salary management" << std::endl;
}

#endif /*_COMPANY_*/