#include <iostream>
#include "Array.h"
using namespace std;

void outputArray(const Array &);

int main()
{
    Array integers1(7);
    outputArray(integers1);   // output Array integers1
    outputArray(3);           // convert 3 to an Array and output Array’s contents
}

// print Array contents
void outputArray(const Array &arrayToOutput)
{
    cout << "The Array received has " << arrayToOutput.getSize()
         << " elements. The contents are:\n" << arrayToOutput << endl;
}
