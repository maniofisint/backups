#include <iostream>
#include <stdexcept>
#include "BasePlusCommissionEmployeeWithInheritance.h"
using namespace std;

BasePlusCommissionEmployeeWithInheritance::BasePlusCommissionEmployeeWithInheritance(
   const string &first, const string &last, const string &ssn,
   double sales, double rate, double salary)
   : CommissionEmployee(first, last, ssn, sales, rate)
{
    setBaseSalary(salary);
}

void BasePlusCommissionEmployeeWithInheritance::setBaseSalary(double salary)
{
   if (salary >= 0.0)
      baseSalary = salary;
   else
      throw invalid_argument( "Salary must be >= 0.0" );
}

double BasePlusCommissionEmployeeWithInheritance::getBaseSalary() const
{
   return baseSalary;
}

double BasePlusCommissionEmployeeWithInheritance::earnings() const
{
   return baseSalary + (commissionRate * grossSales); //getCommissionRate() * getGrossSales();
   //return baseSalary + CommissionEmployee::earnings();
}

void BasePlusCommissionEmployeeWithInheritance::print() const
{
    cout << "base-salaried commission employee: " << firstName //getFirstName()
      << ' ' << lastName //getLastName() //
      << "\nsocial security number: " << socialSecurityNumber //getSocialSecurityNumber() //
      << "\ngross sales: " <<  grossSales //getGrossSales() //
      << "\ncommission rate: " << commissionRate //getCommissionRate() //
      << "\nbase salary: " << baseSalary;

    //CommissionEmployee::print();
    //cout << "\nbase salary: " << baseSalary;
}
