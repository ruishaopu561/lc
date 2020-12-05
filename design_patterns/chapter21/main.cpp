#include <iostream>

#include "singleton.h"

using namespace std;

int main()
{
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();

    if (s1 == s2)
    {
        cout << "两个对象是相同的实例." << endl;
    }

    return 0;
}