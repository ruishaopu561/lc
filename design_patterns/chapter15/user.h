#ifndef _USER_
#define _USER_

#include <iostream>

class User
{
private:
    int id;
    std::string name;

public:
    User(int _id, std::string _name) : id(_id), name(_name){};
    ~User(){};

    int getId();
    void setId(int _id);
    std::string getName(std::string _name);
    void setName(std::string _name);
};

int User::getId()
{
    return id;
}

void User::setId(int _id)
{
    id = _id;
}

std::string User::getName(std::string _name)
{
    return name;
}

void User::setName(std::string _name)
{
    name = _name;
}

class IUser
{
public:
    IUser(){};
    ~IUser(){};

    virtual void insert(User *user) = 0;
    virtual void getUser(int id) = 0;
};

class SqlserverUser : public IUser
{
public:
    SqlserverUser(){};
    ~SqlserverUser(){};

    void insert(User *user);
    void getUser(int id);
};

void SqlserverUser::insert(User *user)
{
    std::cout << "insert an recocrd in SQL server." << std::endl;
}

void SqlserverUser::getUser(int id)
{
    std::cout << "get an user by id from SQL srever." << std::endl;
}

class AccessUser : public IUser
{
public:
    AccessUser(){};
    ~AccessUser(){};

    void insert(User *user);
    void getUser(int id);
};

void AccessUser::insert(User *user)
{
    std::cout << "insert an recocrd in Access." << std::endl;
}

void AccessUser::getUser(int id)
{
    std::cout << "get an user by id from Access." << std::endl;
}

#endif /*_USER_*/