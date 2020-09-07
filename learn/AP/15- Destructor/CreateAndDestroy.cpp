#include <iostream>
#include "CreateAndDestroy.h"

CreateAndDestroy::CreateAndDestroy(int id, string msg)
{
    objectID = id;
    message = msg;
    cout << "Object " << objectID << "   constructor runs   "
         << message << endl;
}

CreateAndDestroy::~CreateAndDestroy()
{
    cout << "Object " << objectID << "   destructor  runs   "
         << message << endl;
}
