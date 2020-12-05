#ifndef HANDSETBRAND_H
#define HANDSETBRAND_H

#include "handsetSoft.h"

class HandsetBrand
{
public:
    HandsetSoft *soft;

    HandsetBrand(){};
    ~HandsetBrand(){};
    void setHandsetSoft(HandsetSoft *_soft);
    virtual void run() = 0;
};

void HandsetBrand::setHandsetSoft(HandsetSoft *_soft)
{
    soft = _soft;
}

class HandsetBrandM : public HandsetBrand
{
public:
    HandsetBrandM(){};
    ~HandsetBrandM(){};
    void run();
};

void HandsetBrandM::run()
{
    soft->run();
}

class HandsetBrandN : public HandsetBrand
{
public:
    HandsetBrandN(){};
    ~HandsetBrandN(){};
    void run();
};

void HandsetBrandN::run()
{
    soft->run();
}

#endif /*HANDSETBRAND_H*/