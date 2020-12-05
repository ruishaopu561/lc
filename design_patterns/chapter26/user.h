#ifndef USER_H
#define USER_H

#include <string>

class User
{
private:
    std::string name;

public:
    User(std::string _name) : name(_name){};
    ~User(){};
    std::string getName();
};

std::string User::getName()
{
    return name;
}
#endif /*USER_H*/