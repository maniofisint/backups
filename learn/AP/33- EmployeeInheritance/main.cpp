#include <iostream>
#include <iomanip>
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployeeWithoutInheritance.h"
#include "BasePlusCommissionEmployeeWithInheritance.h"
using namespace std;

int main()
{
    cout << endl << "-------------------CommissionEmployee-------------------" << endl;
    CommissionEmployee employee1(
      "Sue", "Jones", "222-22-2222", 10000, .06);

    cout << fixed << setprecision(2);

    cout << "Employee information obtained by get functions: \n"
      << "\nFirst name is " << employee1.getFirstName()
      << "\nLast name is " << employee1.getLastName()
      << "\nSocial security number is "
      << employee1.getSocialSecurityNumber()
      << "\nGross sales is " << employee1.getGrossSales()
      << "\nCommission rate is " << employee1.getCommissionRate() << endl;

    employee1.setGrossSales(8000);
    employee1.setCommissionRate(.1);

    cout << "\nUpdated employee1 information output by print function: \n"
      << endl;
    employee1.print();

    cout << "\n\nEmployee's earnings: $" << employee1.earnings() << endl;


    cout << endl << "--------BasePlusCommissionEmployeeWithoutInheritance-------" << endl;
    BasePlusCommissionEmployeeWithoutInheritance
      employee2("Bob", "Lewis", "333-33-3333", 5000, .04, 300);

    cout << fixed << setprecision(2);

    cout << "Employee information obtained by get functions: \n"
      << "\nFirst name is " << employee2.getFirstName()
      << "\nLast name is " << employee2.getLastName()
      << "\nSocial security number is "
      << employee2.getSocialSecurityNumber()
      << "\nGross sales is " << employee2.getGrossSales()
      << "\nCommission rate is " << employee2.getCommissionRate()
      << "\nBase salary is " << employee2.getBaseSalary() << endl;

    employee2.setBaseSalary(1000); // set base salary

    cout << "\nUpdated employee2 information output by print function: \n"
      << endl;
    employee2.print();

    cout << "\n\nEmployee's earnings: $" << employee2.earnings() << endl;

    cout << endl << "---------BasePlusCommissionEmployeeWithInheritance---------" << endl;
    BasePlusCommissionEmployeeWithInheritance
      employee3( "Bob", "Lewis", "333-33-3333", 5000, .04, 300);

    cout << fixed << setprecision(2);

    cout << "Employee information obtained by get functions: \n"
      << "\nFirst name is " << employee3.getFirstName()
      << "\nLast name is " << employee3.getLastName()
      << "\nSocial security number is "
      << employee3.getSocialSecurityNumber()
      << "\nGross sales is " << employee3.getGrossSales()
      << "\nCommission rate is " << employee3.getCommissionRate()
      << "\nBase salary is " << employee3.getBaseSalary() << endl;

    employee3.setBaseSalary(1000); // set base salary

    cout << "\nUpdated employee3 information output by print function: \n"
      << endl;
    employee3.print();

    cout << "\n\nEmployee's earnings: $" << employee3.earnings() << endl;
}
