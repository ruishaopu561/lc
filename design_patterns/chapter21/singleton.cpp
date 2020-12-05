#include "singleton.h"

// 这句对static变量的赋值必不可少，否则getInstance()时会出错；
Singleton *Singleton::instance = nullptr;