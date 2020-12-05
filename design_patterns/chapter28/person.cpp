#include "person.h"
#include "action.h"

void Man::accept(Action *visitor)
{
    visitor->getManConclusion(this);
}

void Woman::accept(Action *visitor)
{
    visitor->getWomanConclusion(this);
}