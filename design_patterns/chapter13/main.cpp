#include <iostream>

#include "personBuilder.h"

using namespace std;

int main()
{
    PersonThinBuilder *thin = new PersonThinBuilder("rsp", 22);
    PersonFatBuilder *fat = new PersonFatBuilder("tyh", 23);

    PersonDirector *pd = new PersonDirector(thin);
    pd->createPerson();

    cout << endl;

    pd->setPeronDirector(fat);
    pd->createPerson();

    return 0;
}