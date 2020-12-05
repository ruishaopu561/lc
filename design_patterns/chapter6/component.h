#ifndef _COMPONENT_
#define _COMPONENT_

#include <iostream>
#include <string>

// 可以类比到穿衣搭配问题，基类是Component类，其余所有的类都是其子类
// 其中子类又分两种，一种是具体对象，一种是装饰器s，装饰器各有不同的类
// 型，根据你需要在客户端搭配。

// 装饰模式是使用setComponent来对对象进行包装的。每个对象的实现和使用
// 就分开了，每个装饰对象只关心自己的功能，不再关心自己如何被添加到对象
// 链中。

class Component
{
public:
    Component();
    ~Component();
    virtual void operation();
};

class ConcreteComponent : public Component
{
public:
    ConcreteComponent(){};
    ~ConcreteComponent(){};
    void operation();
};

void ConcreteComponent::operation()
{
    std::cout << "具体对象的操作" << std::endl;
}

class Decorator : public Component
{
public:
    Component *component;
    Decorator();
    ~Decorator();
    void operation();
    void setComponent(Component *c);
};

void Decorator::operation()
{
    if (component)
    {
        component->operation();
    }
}

void Decorator::setComponent(Component *c)
{
    component = c;
}

class ConcreteDecoratorA : public Decorator
{
private:
    std::string addedState;

public:
    ConcreteDecoratorA(){};
    ~ConcreteDecoratorA(){};
    void operation();
};

void ConcreteDecoratorA::operation()
{
    component->operation();
    addedState = "New state";
    std::cout << "具体装饰对象A的操作" << std::endl;
}

class ConcreteDecoratorB : public Decorator
{
public:
    ConcreteDecoratorB(){};
    ~ConcreteDecoratorB(){};
    void operation();
    void addedBehavior();
};

void ConcreteDecoratorB::operation()
{
    component->operation();
    addedBehavior();
    std::cout << "具体装饰对象B的操作" << std::endl;
}

void ConcreteDecoratorB::addedBehavior()
{
    std::cout << "具体装饰对象B新加的操作" << std::endl;
}

#endif /*_COMPONENT_*/