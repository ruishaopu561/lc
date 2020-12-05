#ifndef _SECRETARY_
#define _SECRETARY_

#include <vector>
#include <string>

class Observer;

class Subject
{
private:
    std::string state;

public:
    std::string getState();
    void setState(std::string _state);

    virtual void attach(Observer *observer) = 0;
    virtual void detach(Observer *observer) = 0;
    virtual void notify() = 0;
};

class Boss : public Subject
{
private:
    std::vector<Observer *> observers;

public:
    Boss(){};
    ~Boss(){};
    void attach(Observer *observer);
    void detach(Observer *observer);
    void notify();
};

class Secretary : public Subject
{
private:
    std::vector<Observer *> observers;

public:
    Secretary(){};
    ~Secretary(){};
    void attach(Observer *observer);
    void detach(Observer *observer);
    void notify();
};

#endif /*_SECRETARY_*/