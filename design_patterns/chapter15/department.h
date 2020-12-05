#ifndef _DEPARTMENT_
#define _DEPARTMENT_

#include <iostream>
#include <string>

class Department
{
private:
    int id;
    std::string name;

public:
    Department(int _id, std::string _name) : id(_id), name(_name){};
    ~Department(){};

    int getId();
    void setId(int _id);
    std::string getName(std::string _name);
    void setName(std::string _name);
};

int Department::getId()
{
    return id;
}

void Department::setId(int _id)
{
    id = _id;
}

std::string Department::getName(std::string _name)
{
    return name;
}

void Department::setName(std::string _name)
{
    name = _name;
}

class IDepartment
{
public:
    IDepartment(){};
    ~IDepartment(){};

    virtual void insert(Department *department) = 0;
    virtual void getDepartment(int id) = 0;
};

class SqlserverDepartment : public IDepartment
{
public:
    SqlserverDepartment(){};
    ~SqlserverDepartment(){};
    void insert(Department *department);
    void getDepartment(int id);
};

void SqlserverDepartment::insert(Department *department)
{
    std::cout << "insert an Department recocrd in SQL server." << std::endl;
}

void SqlserverDepartment::getDepartment(int id)
{
    std::cout << "get an Department recocrd from SQL server." << std::endl;
}

class AccessDepartment : public IDepartment
{
public:
    AccessDepartment(){};
    ~AccessDepartment(){};
    void insert(Department *department);
    void getDepartment(int id);
};

void AccessDepartment::insert(Department *department)
{
    std::cout << "insert an Department recocrd in Access." << std::endl;
}

void AccessDepartment::getDepartment(int id)
{
    std::cout << "get an Department recocrd from Access." << std::endl;
}

#endif /*_DEPARTMENT_*/
