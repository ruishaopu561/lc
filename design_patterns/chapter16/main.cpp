#include <iostream>

#include "work.h"
#include "context.h"
#include "state.h"

using namespace std;

int main()
{
    // Context *c = new Context(new ConcreteStateA(1));
    Context *c = new Context(new ConcreteStateB(1));

    c->request();
    c->request();
    c->request();
    c->request();

    return 0;
}

// int main()
// {
//     Work *project = new Work();
//     project->setHour(9);
//     project->writeProgram();
//     project->setHour(10);
//     project->writeProgram();
//     project->setHour(12);
//     project->writeProgram();
//     project->setHour(13);
//     project->writeProgram();
//     project->setHour(14);
//     project->writeProgram();
//     project->setHour(17);
//     project->writeProgram();

//     // project->setFinished(true);
//     project->setFinished(false);

//     project->writeProgram();
//     project->setHour(19);
//     project->writeProgram();
//     project->setHour(22);
//     project->writeProgram();

//     return 0;
// }