// static data member tracking the number of objects of a class.
#include <iostream>
#include "Employee.h"
using namespace std;

int main()
{
    // no objects exist; use class name and binary scope resolution
    // operator to access static member function getCount
    cout << "Number of employees before instantiation of any objects is "
         << Employee::getCount() << endl; // use class name
    Employee e0("John", "Smith");
    // the following scope creates and destroys
    // Employee objects before main terminates
    {
        Employee e1("Susan", "Baker");
        Employee e2("Robert", "Jones");

        cout << "Number of employees after objects are instantiated is "
             << Employee::getCount();

        cout << "\n\nEmployee 1: "
             << e1.getFirstName() << " " << e1.getLastName()
             << "\nEmployee 2: "
             << e2.getFirstName() << " " << e2.getLastName() << "\n\n";
    } // end nested scope in main

    // no objects exist, so call static member function getCount again
    // using the class name and the binary scope resolution operator
    cout << "\nNumber of employees after objects are deleted is "
         << Employee::getCount() << endl;
}
// define and initialize static data member at global namespace scope
unsigned int Employee::count = 0; // cannot include keyword static

// define static member function that returns number of
// Employee objects instantiated (declared static in Employee.h)
unsigned int Employee::getCount()
{
    return count;
}

// constructor initializes non-static data members and
// increments static data member count
Employee::Employee(const string &first, const string &last)
   : firstName(first), lastName(last)
{
    ++count; // increment static count of employees
    cout << "Employee constructor for " << firstName
        << ' ' << lastName << " called." << endl;
}

// destructor deallocates dynamically allocated memory
Employee::~Employee()
{
    cout << "~Employee() called for " << firstName
        << ' ' << lastName << endl;
    --count; // decrement static count of employees
}

string Employee::getFirstName() const
{
    return firstName;
}

string Employee::getLastName() const
{
    return lastName;
}
