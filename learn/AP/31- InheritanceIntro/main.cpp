#include <iostream>

using namespace std;

class Parent
{
public:
    int parentID;
};

class Child : public Parent
{
public:
    int childId;
};


int main()
{
    Child obj1;
    obj1.childId = 3;
    obj1.parentID = 7;
    cout << "Child Id is: " << obj1.childId
         << ", Parent Id is: " << obj1.parentID;
    return 0;
}
