#ifndef WEBSITEFACTORY_H
#define WEBSITEFACTORY_H

#include <map>
#include <string>

#include "website.h"

class WebsiteFactory
{
private:
    std::map<std::string, Website *> websites;

public:
    WebsiteFactory(){};
    ~WebsiteFactory(){};
    Website *getWebsite(std::string key);
    int getWebsiteCount();
};

Website *WebsiteFactory::getWebsite(std::string key)
{
    if (websites.find(key) == websites.end())
    {
        websites[key] = new ConcreteWebsite(key);
    }
    return websites[key];
}

int WebsiteFactory::getWebsiteCount()
{
    return websites.size();
}

#endif /*WEBSITEFACTORY_H*/