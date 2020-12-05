#include <iostream>

#include "user.h"
#include "department.h"
#include "factory.h"

using namespace std;

int main()
{
    User *user = new User(1, "huhansan");
    Department *department = new Department(1, "abcd");

    IFactory *factory = new AccessFactory();

    IUser *iu = factory->createUser();
    iu->insert(user);
    iu->getUser(1);

    IDepartment *id = factory->createDepartment();
    id->insert(department);
    id->getDepartment(1);

    return 0;
}