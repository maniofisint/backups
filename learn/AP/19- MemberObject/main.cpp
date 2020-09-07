#include <iostream>
#include <stdexcept>
#include "Employee.h"
#include "Date.h"
using namespace std;

int main()
{
   Date birth(10, 24, 1986);
   Date hire(9, 1, 2012);
   Employee lecturer("Mohammad", "Asgaripour", birth, hire);

   cout << endl;
   lecturer.print();
}
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
Date::Date(int mn, int dy, int yr)
{
    if (mn > 0 && mn <= monthsPerYear) // validate the month
        month = mn;
    else
        throw invalid_argument("month must be 1-12");

    year = yr;
    day = checkDay(dy); // validate the day

    cout << "Date object constructor for date ";
    print();
    cout << endl;
}

void Date::print() const
{
    cout << month << '/' << day << '/' << year;
}

Date::~Date()
{
    cout << "Date object destructor for date ";
    print();
    cout << endl;
}

// utility function to confirm proper day value based on
// month and year; handles leap years, too
unsigned int Date::checkDay(int testDay) const
{
   const int daysPerMonth[] =
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

   // determine whether testDay is valid for specified month
   if(testDay > 0 && testDay <= daysPerMonth[month])
        return testDay;

   // February 29 check for leap year
   if((month == 2 && testDay == 29) &&
      (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
      return testDay;

   throw invalid_argument( "Invalid day for current month and year" );
}

