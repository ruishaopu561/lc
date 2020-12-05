#ifndef _COMPONENT_
#define _COMPONENT_

#include <iostream>
#include <string>
#include <vector>

class Component
{
public:
    std::string name;

    Component(std::string _name) : name(_name){};
    ~Component(){};
    virtual void add(Component *c) = 0;
    virtual void remove(Component *c) = 0;
    virtual void display(int depth) = 0;
};

class Leaf : public Component
{
public:
    Leaf(std::string _name) : Component(_name){};
    ~Leaf(){};
    void add(Component *c);
    void remove(Component *c);
    void display(int depth);
};

void Leaf::add(Component *c)
{
    std::cout << "Cannot add to a leaf." << std::endl;
}

void Leaf::remove(Component *c)
{
    std::cout << "Cannot remove from a leaf." << std::endl;
}

void Leaf::display(int depth)
{
    std::cout << "-" << depth << " " << name << std::endl;
}

class Composite : public Component
{
private:
    std::vector<Component *> children;

public:
    Composite(std::string _name) : Component(_name){};
    ~Composite(){};
    void add(Component *c);
    void remove(Component *c);
    void display(int depth);
};

void Composite::add(Component *c)
{
    children.push_back(c);
}

void Composite::remove(Component *c)
{
    for (int i = 0; i < children.size(); i++)
    {
        if (children[i] == c)
        {
            children.erase(children.begin() + i);
            return;
        }
    }
}

void Composite::display(int depth)
{
    std::cout << "-" << depth << " " << name << std::endl;
    for (int i = 0; i < children.size(); i++)
    {
        children[i]->display(depth + 1);
    }
}

#endif /*_COMPONENT_*/