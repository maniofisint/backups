#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>

using namespace std;
class CommissionEmployee
{
public:
    CommissionEmployee(const std::string &, const std::string &,
        const std::string &, double = 0.0, double = 0.0);

    void setFirstName(const std::string &);
    std::string getFirstName() const;

    void setLastName(const std::string &);
    std::string getLastName() const;

    void setSocialSecurityNumber(const std::string &);
    std::string getSocialSecurityNumber() const;

    void setGrossSales(double);
    double getGrossSales() const;

    void setCommissionRate(double);
    double getCommissionRate() const;

    virtual double earnings() const;
    virtual void print() const;
protected:
//private:
    std::string firstName;
    std::string lastName;
    std::string socialSecurityNumber;
    double grossSales;
    double commissionRate;
};

CommissionEmployee::CommissionEmployee(
   const string &first, const string &last, const string &ssn,
   double sales, double rate)
{
    firstName = first;
    lastName = last;
    socialSecurityNumber = ssn;
    setGrossSales(sales);
    setCommissionRate(rate);
}

void CommissionEmployee::setFirstName(const string &first)
{
    firstName = first;
}

string CommissionEmployee::getFirstName() const
{
    return firstName;
}

void CommissionEmployee::setLastName(const string &last)
{
    lastName = last;
}

string CommissionEmployee::getLastName() const
{
    return lastName;
}

void CommissionEmployee::setSocialSecurityNumber(const string &ssn)
{
    socialSecurityNumber = ssn;
}

string CommissionEmployee::getSocialSecurityNumber() const
{
    return socialSecurityNumber;
}

void CommissionEmployee::setGrossSales(double sales)
{
    if(sales >= 0.0)
        grossSales = sales;
    else
        throw invalid_argument("Gross sales must be >= 0.0");
}

double CommissionEmployee::getGrossSales() const
{
    return grossSales;
}

void CommissionEmployee::setCommissionRate(double rate)
{
    if (rate > 0.0 && rate < 1.0)
        commissionRate = rate;
    else
        throw invalid_argument("Commission rate must be > 0.0 and < 1.0");
}

double CommissionEmployee::getCommissionRate() const
{
    return commissionRate;
}

double CommissionEmployee::earnings() const
{
    return commissionRate * grossSales;
}

void CommissionEmployee::print() const
{
    cout << "commission employee: " << firstName << ' ' << lastName
      << "\nsocial security number: " << socialSecurityNumber
      << "\ngross sales: " << grossSales
      << "\ncommission rate: " << commissionRate;
}
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

int main()
{
    CommissionEmployee         commissionEmployee        ("Sue", "Jones", "222-22-2222", 10000, .06);
    BasePlusCommissionEmployee basePlusCommissionEmployee("Bob", "Lewis", "333-33-3333", 5000, .04, 300);
    CommissionEmployee         *commissionEmployeePtr;
    BasePlusCommissionEmployee *basePlusCommissionEmployeePtr;

    commissionEmployee.print();
    cout << "\n------------------------------------\n";
    basePlusCommissionEmployee.print();
    cout << "\n------------------------------------\n";

    commissionEmployeePtr = &commissionEmployee;
    commissionEmployeePtr->print();
    cout << "\n------------------------------------\n";
    basePlusCommissionEmployeePtr = &basePlusCommissionEmployee;
    basePlusCommissionEmployeePtr->print();
    cout << "\n------------------------------------\n";

    commissionEmployeePtr = &basePlusCommissionEmployee;
    commissionEmployeePtr->print();
    cout << "\n------------------------------------\n";

    return 0;
}
