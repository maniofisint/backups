 // Demonstrating class PhoneNumber's overloaded stream insertion
// and stream extraction operators.
#include <iostream>
#include <iomanip>
#include "PhoneNumber.h"
using namespace std;

int main()
{
    PhoneNumber phone;

    cout << "Enter phone number in the form (123) 456-7890:" << endl;

    // cin >> phone invokes operator>> by implicitly issuing
    // the global function call operator>>( cin, phone )
    cin >> phone;

    cout << "The phone number entered was: ";

    // cout << phone invokes operator<< by implicitly issuiniog
    // the global function call operator<<( cout, phone )
    cout << phone << endl;
	cout << phone ;
    //operator<<(cout, phone);
    //operator<<(operator<<(cout, phone), phone);
    //phone << cout;
}
// overloaded stream insertion operator; cannot be
// a member function if we would like to invoke it with
// cout << somePhoneNumber;
ostream &operator<<(ostream &output, const PhoneNumber &number)
{
   output << "(" << number.areaCode << ") "
      << number.exchange << "-" << number.line;
   return output; // enables cout << a << b << c;
}

// overloaded stream extraction operator; cannot be
// a member function if we would like to invoke it with
// cin >> somePhoneNumber;
istream &operator>>(istream &input, PhoneNumber &number)
{
   input.ignore(); // skip (
   input >> setw(3) >> number.areaCode; // input area code
   input.ignore(2); // skip ) and space
   input >> setw(3) >> number.exchange; // input exchange
   input.ignore(); // skip dash (-)
   input >> setw(4) >> number.line; // input line
   return input; // enables cin >> a >> b >> c;
}

ostream &PhoneNumber::operator<<(ostream &output)
{
   output << "(" << areaCode << ") "
      << exchange << "-" << line;
   return output; // enables cout << a << b << c;
}
