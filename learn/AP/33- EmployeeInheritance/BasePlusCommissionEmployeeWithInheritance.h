#ifndef BASEPLUSINH_H
#define BASEPLUSINH_H

#include <string>
#include "CommissionEmployee.h"

class BasePlusCommissionEmployeeWithInheritance : public CommissionEmployee
{
public:
    BasePlusCommissionEmployeeWithInheritance(const std::string &, const std::string &,
      const std::string &, double = 0.0, double = 0.0, double = 0.0);

    void setBaseSalary(double);
    double getBaseSalary() const;

    double earnings() const;
    void print() const;
private:
    double baseSalary;
};
#endif
