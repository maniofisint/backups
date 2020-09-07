#include <iostream>
#include <stdexcept>
#include "BasePlusCommissionEmployeeWithoutInheritance.h"
using namespace std;

BasePlusCommissionEmployeeWithoutInheritance::BasePlusCommissionEmployeeWithoutInheritance(
   const string &first, const string &last, const string &ssn,
   double sales, double rate, double salary)
{
    firstName = first;
    lastName = last;
    socialSecurityNumber = ssn;
    setGrossSales(sales);
    setCommissionRate(rate);
    setBaseSalary(salary);
}

void BasePlusCommissionEmployeeWithoutInheritance::setFirstName(const string &first)
{
    firstName = first;
}

string BasePlusCommissionEmployeeWithoutInheritance::getFirstName() const
{
    return firstName;
}

void BasePlusCommissionEmployeeWithoutInheritance::setLastName(const string &last)
{
    lastName = last;
}

string BasePlusCommissionEmployeeWithoutInheritance::getLastName() const
{
    return lastName;
}

void BasePlusCommissionEmployeeWithoutInheritance::setSocialSecurityNumber(const string &ssn)
{
    socialSecurityNumber = ssn;
}

string BasePlusCommissionEmployeeWithoutInheritance::getSocialSecurityNumber() const
{
    return socialSecurityNumber;
}

void BasePlusCommissionEmployeeWithoutInheritance::setGrossSales(double sales)
{
    if (sales >= 0.0)
        grossSales = sales;
    else
        throw invalid_argument("Gross sales must be >= 0.0");
}

double BasePlusCommissionEmployeeWithoutInheritance::getGrossSales() const
{
    return grossSales;
}

void BasePlusCommissionEmployeeWithoutInheritance::setCommissionRate(double rate)
{
    if (rate > 0.0 && rate < 1.0)
        commissionRate = rate;
    else
        throw invalid_argument("Commission rate must be > 0.0 and < 1.0");
}

double BasePlusCommissionEmployeeWithoutInheritance::getCommissionRate() const
{
    return commissionRate;
}

void BasePlusCommissionEmployeeWithoutInheritance::setBaseSalary(double salary)
{
    if (salary >= 0.0)
        baseSalary = salary;
    else
        throw invalid_argument("Salary must be >= 0.0");
}

double BasePlusCommissionEmployeeWithoutInheritance::getBaseSalary() const
{
    return baseSalary;
}

double BasePlusCommissionEmployeeWithoutInheritance::earnings() const
{
    return baseSalary + (commissionRate * grossSales);
}

void BasePlusCommissionEmployeeWithoutInheritance::print() const
{
    cout << "commission employee: " << firstName << ' ' << lastName
      << "\nsocial security number: " << socialSecurityNumber
      << "\ngross sales: " << grossSales
      << "\ncommission rate: " << commissionRate
      << "\nbase salary: " << baseSalary;
}
