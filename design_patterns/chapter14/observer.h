#ifndef _OBSERVER_
#define _OBSERVER_

#include <string>

class Subject;

class Observer
{
public:
    std::string name;
    Subject *sub;

    Observer(std::string _name, Subject *_sub) : name(_name), sub(_sub){};
    ~Observer(){};
    virtual void update() = 0;
};

class StockObserver : public Observer
{
public:
    StockObserver(std::string _name, Subject *_sub) : Observer(_name, _sub){};
    ~StockObserver(){};
    void update();
};

class NBAObserver : public Observer
{
public:
    NBAObserver(std::string _name, Subject *_sub) : Observer(_name, _sub){};
    ~NBAObserver(){};
    void update();
};

#endif /*_OBSERVER_*/