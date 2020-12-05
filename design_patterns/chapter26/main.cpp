#include <iostream>

#include "website.h"
#include "websiteFactory.h"

using namespace std;

int main()
{
    WebsiteFactory *f = new WebsiteFactory();

    Website *fx = f->getWebsite("产品展示");
    fx->use(new User("小菜"));

    Website *fy = f->getWebsite("产品展示");
    fy->use(new User("大鸟"));

    Website *fz = f->getWebsite("产品展示");
    fz->use(new User("娇娇"));

    Website *fl = f->getWebsite("博客");
    fl->use(new User("老顽童"));

    Website *fm = f->getWebsite("博客");
    fm->use(new User("桃谷六仙"));

    Website *fn = f->getWebsite("博客");
    fn->use(new User("南海鳄神"));

    std::cout << "网站分类总数为 "<< f->getWebsiteCount() <<std::endl;
    return 0;
}