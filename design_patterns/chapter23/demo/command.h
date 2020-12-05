#ifndef COMMAND_H
#define COMMAND_H

#include <string>

#include "barbecuer.h"

class Command
{
private:
    std::string name;

public:
    Barbecuer *receiver;

    Command(Barbecuer *_receiver, std::string _name) : receiver(_receiver), name(_name){};
    ~Command(){};
    std::string getName() { return name; }
    virtual void excuteCommand() = 0;
};

class BakeMuttonCommand : public Command
{
public:
    BakeMuttonCommand(Barbecuer *_receiver) : Command(_receiver, "烤羊肉串"){};
    ~BakeMuttonCommand(){};
    void excuteCommand();
};

void BakeMuttonCommand::excuteCommand()
{
    receiver->bakeMutton();
}

class BakeChickenWingCommand : public Command
{
public:
    BakeChickenWingCommand(Barbecuer *_receiver) : Command(_receiver, "烤鸡翅"){};
    ~BakeChickenWingCommand(){};
    void excuteCommand();
};

void BakeChickenWingCommand::excuteCommand()
{
    receiver->bakeChickenWing();
}

#endif /*COMMAND_H*/