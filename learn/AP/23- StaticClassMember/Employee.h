// Employee class definition with a static data member to
// track the number of Employee objects in memory
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee
{
    public:
        Employee(const std::string &, const std::string &);
        ~Employee();
        std::string getFirstName() const;
        std::string getLastName() const;

        // static member function
        static unsigned int getCount();                         // return # of objects instantiated
    private:
        std::string firstName;
        std::string lastName;

        // static data
        static unsigned int count;                              // number of objects instantiated
};

#endif
