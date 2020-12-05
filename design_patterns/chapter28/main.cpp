#include <vector>

#include "action.h"
#include "person.h"
#include "objectStructure.h"

using namespace std;

int main()
{
    ObjectStructure *o= new ObjectStructure();
    o->attach(new Man());
    o->attach(new Woman());

    Success *v1 = new Success();
    o->display(v1);

    Failing *v2 = new Failing();
    o->display(v2);

    Amativeness *v3 = new Amativeness();
    o->display(v3);

    return 0;
}