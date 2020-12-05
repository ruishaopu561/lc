#include "visitor.h"
#include "element.h"
#include "objectStructure.h"

using namespace std;

int main()
{
    ObjectStructure *o = new ObjectStructure();
    o->attach(new ConcreteElementA("Element A"));
    o->attach(new ConcreteElementB("Element B"));

    ConcreteVisitor1 *v1 = new ConcreteVisitor1("Visitor 1");
    ConcreteVisitor2 *v2 = new ConcreteVisitor2("Visitor 2");

    o->display(v1);
    o->display(v2);

    return 0;
}