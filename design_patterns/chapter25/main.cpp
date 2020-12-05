#include "country.h"
#include "unitedNations.h"

using namespace std;

int main()
{
    UnitedNationsSecurityCouncil *UNSC = new UnitedNationsSecurityCouncil();

    USA *c1 = new USA(UNSC);
    Irap *c2 = new Irap(UNSC);

    UNSC->setColleague1(c1);
    UNSC->setColleague2(c2);

    c1->declare("不准研制核武器，否则要发动战争！");
    c2->declare("我们没有核武器，也不怕侵略！");

    return 0;
}