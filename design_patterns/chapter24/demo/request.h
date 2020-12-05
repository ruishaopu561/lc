#ifndef REQUEST_H
#define REQUEST_H

#include <string>

class Request
{
private:
    std::string requestType;
    std::string requestContent;
    int number;

public:
    Request(){};
    ~Request(){};
    std::string getRequestType();
    void setRequestType(std::string _requestType);
    std::string getRequestContent();
    void setRequestContent(std::string _requestContent);
    int getNumber();
    void setNumber(int _number);
};

std::string Request::getRequestType()
{
    return requestType;
}

void Request::setRequestType(std::string _requestType)
{
    requestType = _requestType;
}

std::string Request::getRequestContent()
{
    return requestContent;
}

void Request::setRequestContent(std::string _requestContent)
{
    requestContent = _requestContent;
}

int Request::getNumber()
{
    return number;
}

void Request::setNumber(int _number)
{
    number = _number;
}

#endif /*REQUEST_H*/