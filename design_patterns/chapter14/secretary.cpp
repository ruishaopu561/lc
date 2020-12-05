#include "secretary.h"
#include "observer.h"

std::string Subject::getState()
{
    return state;
}

void Subject::setState(std::string _state)
{
    state = _state;
}

void Boss::attach(Observer *observer)
{
    observers.push_back(observer);
}

void Boss::detach(Observer *observer)
{
    for (int i = 0; i < observers.size(); i++)
    {
        if (observers[i] == observer)
        {
            observers.erase(observers.begin() + i);
        }
    }
}

void Boss::notify()
{
    for (int i = 0; i < observers.size(); i++)
    {
        observers[i]->update();
    }
}

void Secretary::attach(Observer *observer)
{
    observers.push_back(observer);
}

void Secretary::detach(Observer *observer)
{
    for (int i = 0; i < observers.size(); i++)
    {
        if (observers[i] == observer)
        {
            observers.erase(observers.begin() + i);
        }
    }
}

void Secretary::notify()
{
    for (int i = 0; i < observers.size(); i++)
    {
        observers[i]->update();
    }
}