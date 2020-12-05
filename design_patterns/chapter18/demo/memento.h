#ifndef _MEMENTO_
#define _MEMENTO_

#include <string>

class Memento
{
private:
    std::string state;
public:
    Memento(std::string _state):state(_state){};
    ~Memento(){};
    std::string getState();
};

std::string Memento::getState()
{
    return state;
}

#endif /*_MEMENTO_*/