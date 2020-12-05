#ifndef WEBSITE_H
#define WEBSITE_H

#include <iostream>
#include <string>

#include "user.h"

class Website
{
private:
    std::string name;

public:
    Website(std::string _name) : name(_name){};
    ~Website(){};
    std::string getName();
    virtual void use(User *user) = 0;
};

std::string Website::getName()
{
    return name;
}

class ConcreteWebsite : public Website
{
public:
    ConcreteWebsite(std::string _name) : Website(_name){};
    ~ConcreteWebsite(){};
    void use(User *user);
};

void ConcreteWebsite::use(User *user)
{
    std::cout << "网站分类：" << getName() << " 用户：" << user->getName() << std::endl;
}

#endif /*WEBSITE_H*/