// Array class test program.
#include <iostream>
#include <stdexcept>
#include "Array.h"
using namespace std;

int main()
{
    Array integers1(3); // seven-element Array
    Array integers2;    // 5-element Array by default

    cout << "Size of Array integers1 is "
         << integers1.getSize()
         << "\nArray after initialization:\n" << integers1;

    cout << "\nSize of Array integers2 is "
         << integers2.getSize()
         << "\nArray after initialization:\n" << integers2;

    cout << "\nEnter " << integers1.getSize() + integers2.getSize()
         << " integers:" << endl;
    cin >> integers1 >> integers2;

    cout << "\nAfter input, the Arrays contain:\n"
         << "integers1:\n" << integers1
         << "integers2:\n" << integers2;

    // use overloaded inequality (!=) operator
    cout << "\nEvaluating: integers1 != integers2" << endl;

    if (integers1 != integers2)
        cout << "integers1 and integers2 are not equal" << endl;

    // create Array integers3 using integers1 as an
    // initializer; print size and contents
    Array integers3(integers1); // invokes copy constructor

    cout << "\nintegers1[0] is " << integers1[0];
    cout << "\nintegers3[0] is " << integers3[0];
    integers1[0] = 48;
    cout << "\nintegers1[0] is " << integers1[0];
    cout << "\nintegers3[0] is " << integers3[0];

    cout << "\nSize of Array integers3 is "
         << integers3.getSize()
         << "\nArray after initialization:\n" << integers3;

    // use overloaded assignment (=) operator
    cout << "\nAssigning integers2 to integers1:" << endl;
    integers1 = integers2; // note target Array is smaller

    cout << "integers1:\n" << integers1
         << "integers2:\n" << integers2;

    // use overloaded equality (==) operator
    cout << "\nEvaluating: integers1 == integers2" << endl;

    if (integers1 == integers2)
        cout << "integers1 and integers2 are equal" << endl;

    // use overloaded subscript operator to create rvalue
    cout << "\nintegers1[4] is " << integers1[4];

    // use overloaded subscript operator to create lvalue
    cout << "\n\nAssigning 1000 to integers1[4]" << endl;
    integers1[4] = 1000;
    cout << "integers1:\n" << integers1;

    // attempt to use out-of-range subscript
    try
    {
        cout << "\nAttempt to assign 1000 to integers1[15]" << endl;
        integers1[15] = 1000; // ERROR: subscript out of range
    }
    catch (out_of_range &ex)
    {
        cout << "An exception occurred: " << ex.what() << endl;
    }
}
