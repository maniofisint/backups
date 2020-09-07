// Employee class member-function definitions.
#include <iostream>
#include "Employee.h"
#include "Date.h"
using namespace std;

// constructor uses member initializer list to pass initializer
// values to constructors of member objects
Employee::Employee(const string &first, const string &last,
   const Date &dateOfBirth, const Date &dateOfHire)
   : firstName(first),
     lastName(last),
     birthDate(dateOfBirth),
     hireDate(dateOfHire)
{
   cout << "Employee object constructor: "
      << firstName << ' ' << lastName << endl;
}

void Employee::print() const
{
   cout << lastName << ", " << firstName << "  Hired: ";
   hireDate.print();
   cout << "  Birthday: ";
   birthDate.print();
   cout << endl;
}

Employee::~Employee()
{
   cout << "Employee object destructor: "
      << lastName << ", " << firstName << endl;
}

