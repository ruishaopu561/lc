#include "action.h"
#include "person.h"

#include <iostream>

void Success::getManConclusion(Man *man)
{
    std::cout << "男人成功时，背后多半有一个伟大的女人。" << std::endl;
}

void Success::getWomanConclusion(Woman *woman)
{
    std::cout << "女人成功时，背后大多有一个不成功的男人。" << std::endl;
}

void Failing::getManConclusion(Man *man)
{
    std::cout << "男人失败时，闷头喝酒，谁也不用劝。" << std::endl;
}

void Failing::getWomanConclusion(Woman *woman)
{
    std::cout << "女人失败时，眼泪汪汪，谁也劝不了。" << std::endl;
}

void Amativeness::getManConclusion(Man *man)
{
    std::cout << "男人恋爱时，凡事不懂也要装懂。" << std::endl;
}

void Amativeness::getWomanConclusion(Woman *woman)
{
    std::cout << "女人恋爱时，遇事懂也装作不懂。" << std::endl;
}