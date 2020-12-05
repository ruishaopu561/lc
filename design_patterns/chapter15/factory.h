#ifndef _Factory_
#define _Factory_

#include "user.h"
#include "department.h"

class IFactory
{
public:
    IFactory(){};
    ~IFactory(){};

    virtual IUser* createUser()=0;
    virtual IDepartment* createDepartment()=0;
};

class SqlServerFactory:public IFactory
{
public:
    SqlServerFactory(){};
    ~SqlServerFactory(){};

    IUser* createUser();
    IDepartment* createDepartment();
};

IUser* SqlServerFactory::createUser()
{
    return new SqlserverUser();
}

IDepartment* SqlServerFactory::createDepartment()
{
    return new SqlserverDepartment();
}

class AccessFactory:public IFactory
{
public:
    AccessFactory(){};
    ~AccessFactory(){};

    IUser* createUser();
    IDepartment* createDepartment();
};

IUser* AccessFactory::createUser()
{
    return new AccessUser();
}

IDepartment* AccessFactory::createDepartment()
{
    return new AccessDepartment();
}


#endif /*_Factory_*/