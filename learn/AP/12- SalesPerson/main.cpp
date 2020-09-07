#include <iostream>
#include <iomanip>
#include "SalesPerson.h"
using namespace std;

SalesPerson::SalesPerson()
{
    for(int i = 0; i < monthsPerYear; i++)
        sales[i] = 0.0;
} // end SalesPerson constructor
void SalesPerson::getSalesFromUser()
{
    double salesFigure;
    for(int i = 1; i <= monthsPerYear; i++)
    {
        cout << "Enter sales amount for month " << i << ": ";
        cin >> salesFigure;
        setSales(i, salesFigure);
    } // end for
} // end function getSalesFromUser
void SalesPerson::setSales(int month, double amount)
{
    if(month >= 1 && month <= monthsPerYear && amount > 0)
        sales[month - 1] = amount; // adjust for subscripts 0-11
    else // invalid month or amount value
        cout << "Invalid month or sales figure" << endl;
} // end function setSales
void SalesPerson::printAnnualSales()
{
    cout << setprecision(2) << fixed
    << "\nThe total annual sales are: $"
    << totalAnnualSales() << endl; // call utility function
} // end function printAnnualSales

double SalesPerson::totalAnnualSales()
{
    double total = 0.0; // initialize total
    for(int i = 0; i < monthsPerYear; i++) // summarize sales results
        total += sales[i]; // add month i sales to total
    return total;
} // end function totalAnnualSales

int main()
{
    SalesPerson s;

    s.getSalesFromUser();
    s.printAnnualSales();
    return 0;

}
