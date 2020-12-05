#ifndef SINGLETON_H
#define SINGLETON_H

class Singleton
{
private:
    static Singleton *instance; // 只是声明，要在.cpp里定义；
    Singleton(){}; // 构造函数设为 private，创建对象时调用 public 的 getInstance()；
    ~Singleton(){};

public:
    static Singleton *getInstance()
    {
        if (!instance)
        {
            instance = new Singleton();
        }
        return instance;
    }
};

#endif /*SINGLETON_H*/