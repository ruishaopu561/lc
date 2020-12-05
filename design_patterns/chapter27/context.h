#ifndef CONTEXT_H
#define CONTEXT_H

#include <string>

class Context
{
private:
    std::string input;
    std::string output;

public:
    Context(){};
    ~Context(){};
    std::string getInput();
    void setInput(std::string _input);
    std::string getOutput();
    void setOutput(std::string _output);
};

std::string Context::getInput()
{
    return input;
}

void Context::setInput(std::string _input)
{
    input = _input;
}

std::string Context::getOutput()
{
    return output;
}

void Context::setOutput(std::string _output)
{
    output = _output;
}

#endif /*CONTEXT_H*/