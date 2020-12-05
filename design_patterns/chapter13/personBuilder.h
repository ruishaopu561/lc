#ifndef _PERSONBUILDER_
#define _PERSONBUILDER_

#include <iostream>
#include <string>

class PersonBuilder
{
private:
    std::string name;
    int age;

public:
    PersonBuilder(std::string _name, int _age) : name(_name), age(_age){};
    ~PersonBuilder(){};
    virtual void buildHead() = 0;
    virtual void buildBody() = 0;
    virtual void buildArmLeft() = 0;
    virtual void buildArmRight() = 0;
    virtual void buildLegLeft() = 0;
    virtual void buildLegRight() = 0;
};

class PersonThinBuilder : public PersonBuilder
{
public:
    PersonThinBuilder(std::string _name, int _age) : PersonBuilder(_name, _age){};
    ~PersonThinBuilder(){};
    virtual void buildHead();
    virtual void buildBody();
    virtual void buildArmLeft();
    virtual void buildArmRight();
    virtual void buildLegLeft();
    virtual void buildLegRight();
};

void PersonThinBuilder::buildHead()
{
    std::cout << "This is thin head." << std::endl;
}

void PersonThinBuilder::buildBody()
{
    std::cout << "This is thin body." << std::endl;
}

void PersonThinBuilder::buildArmLeft()
{
    std::cout << "This is thin left arm." << std::endl;
}

void PersonThinBuilder::buildArmRight()
{
    std::cout << "This is thin right arm." << std::endl;
}

void PersonThinBuilder::buildLegLeft()
{
    std::cout << "This is thin left leg." << std::endl;
}

void PersonThinBuilder::buildLegRight()
{
    std::cout << "This is thin right leg." << std::endl;
}

class PersonFatBuilder : public PersonBuilder
{
public:
    PersonFatBuilder(std::string _name, int _age) : PersonBuilder(_name, _age){};
    ~PersonFatBuilder(){};
    virtual void buildHead();
    virtual void buildBody();
    virtual void buildArmLeft();
    virtual void buildArmRight();
    virtual void buildLegLeft();
    virtual void buildLegRight();
};

void PersonFatBuilder::buildHead()
{
    std::cout << "This is fat head." << std::endl;
}

void PersonFatBuilder::buildBody()
{
    std::cout << "This is fat body." << std::endl;
}

void PersonFatBuilder::buildArmLeft()
{
    std::cout << "This is fat left arm." << std::endl;
}

void PersonFatBuilder::buildArmRight()
{
    std::cout << "This is fat right arm." << std::endl;
}

void PersonFatBuilder::buildLegLeft()
{
    std::cout << "This is fat left leg." << std::endl;
}

void PersonFatBuilder::buildLegRight()
{
    std::cout << "This is fat right leg." << std::endl;
}

// 指挥者Director，建造者模式中非常重要的类，用它来控制建造过程，
// 也用它来隔离用户与建造过程的关联。
class PersonDirector
{
private:
    PersonBuilder *pb;

public:
    PersonDirector(PersonBuilder *_pb) : pb(_pb){};
    ~PersonDirector(){};
    void setPeronDirector(PersonBuilder *new_pb);
    void createPerson();
};

void PersonDirector::setPeronDirector(PersonBuilder *new_pb)
{
    pb = new_pb;
}

void PersonDirector::createPerson()
{
    pb->buildHead();
    pb->buildBody();
    pb->buildArmLeft();
    pb->buildArmRight();
    pb->buildLegLeft();
    pb->buildLegRight();
}

#endif /*_PERSONBUILDER_*/