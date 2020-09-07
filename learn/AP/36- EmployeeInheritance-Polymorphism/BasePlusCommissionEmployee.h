#ifndef BASEPLUSINH_H
#define BASEPLUSINH_H

#include <string>
#include <iostream>
#include <stdexcept>
#include "CommissionEmployee.h"
using namespace std;
class BasePlusCommissionEmployee : public CommissionEmployee
{
public:
    BasePlusCommissionEmployee(const std::string &, const std::string &,
      const std::string &, double = 0.0, double = 0.0, double = 0.0);

    void setBaseSalary(double);
    double getBaseSalary() const;

    virtual double earnings() const;
    virtual void print() const;
private:
    double baseSalary;
};
BasePlusCommissionEmployee::BasePlusCommissionEmployee(
   const string &first, const string &last, const string &ssn,
   double sales, double rate, double salary)
   : CommissionEmployee(first, last, ssn, sales, rate)
{
    setBaseSalary(salary);
}

void BasePlusCommissionEmployee::setBaseSalary(double salary)
{
   if (salary >= 0.0)
      baseSalary = salary;
   else
      throw invalid_argument( "Salary must be >= 0.0" );
}

double BasePlusCommissionEmployee::getBaseSalary() const
{
   return baseSalary;
}

double BasePlusCommissionEmployee::earnings() const
{
   return baseSalary + (commissionRate * grossSales); //getCommissionRate() * getGrossSales();
   //return baseSalary + CommissionEmployee::earnings();
}

void BasePlusCommissionEmployee::print() const
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
#endif
