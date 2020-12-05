#ifndef _WORK_
#define _WORK_

#include <iostream>

class Work
{
private:
    int hour;
    bool finished;

public:
    Work(){};
    ~Work(){};
    int getHour();
    void setHour(int _hour);
    bool getFinished();
    void setFinished(bool _finished);
    void writeProgram();
};

int Work::getHour()
{
    return hour;
}

void Work::setHour(int _hour)
{
    hour = _hour;
}

bool Work::getFinished()
{
    return finished;
}

void Work::setFinished(bool _finished)
{
    finished = _finished;
}

void Work::writeProgram()
{
    if (hour < 12)
    {
        std::cout << "current time: " << hour << " everything works well" << std::endl;
    }
    else if (hour < 13)
    {
        std::cout << "current time: " << hour << " start sleeping" << std::endl;
    }
    else if (hour < 17)
    {
        std::cout << "current time: " << hour << " keep going" << std::endl;
    }
    else
    {
        if (finished)
        {
            std::cout << "current time: " << hour << " go back home" << std::endl;
        }
        else
        {
            if (hour < 21)
            {
                std::cout << "current time: " << hour << " exhausted" << std::endl;
            }
            else
            {
                std::cout << "current time: " << hour << " sleeping now" << std::endl;
            }
        }
    }
}

#endif /*_WORK_*/