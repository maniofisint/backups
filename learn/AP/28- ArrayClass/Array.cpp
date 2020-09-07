// Array class member- and friend-function definitions.
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <initializer_list>

#include "Array.h" // Array class definition
using namespace std;

// default constructor for class Array (default size 10)
Array::Array(int arraySize)
   : size(arraySize > 0 ? arraySize :
        throw invalid_argument("Array size must be greater than 0")),
     ptr(new int[size])
{
   for(size_t i = 0; i < size; ++i)
      ptr[i] = 0;   // set pointer-based array element
}

// copy constructor for class Array;
// must receive a reference to an Array
Array::Array(const Array &arrayToCopy)
   : size(arrayToCopy.size),
     ptr(new int[size])
{
    for(size_t i = 0; i < size; ++i)
        ptr[i] = arrayToCopy.ptr[i];
}

// destructor for class Array
Array::~Array()
{
    delete[] ptr;
}

size_t Array::getSize() const
{
    return size;
}

// overloaded assignment operator;
// const return avoids: ( a1 = a2 ) = a3
const Array &Array::operator=(const Array &right)
{
    if(&right != this) // avoid self-assignment
    {
        // for Arrays of different sizes, deallocate original
        // left-side Array, then allocate new left-side Array
        if (size != right.size)
        {
            delete[] ptr;           // release space
            size = right.size;      // resize this object
            ptr = new int[size];    // create space for Array copy
        }

        for (size_t i = 0; i < size; ++i)
            ptr[i] = right.ptr[i]; // copy array into object
    }

    return *this; // enables x = y = z, for example
}

// determine if two Arrays are equal and
// return true, otherwise return false
bool Array::operator==(const Array &right) const
{
    if (size != right.size)
        return false;

    for (size_t i = 0; i < size; ++i)
        if (ptr[i] != right.ptr[i])
            return false;

    return true;
}

// overloaded subscript operator for non-const Arrays;
// reference return creates a modifiable lvalue
int &Array::operator[](int subscript)
{
    if (subscript < 0 || subscript >= size)
        throw out_of_range( "Subscript out of range" );

    return ptr[subscript];
}

// overloaded subscript operator for const Arrays
// const reference return creates an rvalue
int Array::operator[](int subscript) const
{
    if (subscript < 0 || subscript >= size)
        throw out_of_range("Subscript out of range");

    return ptr[subscript];
}

istream &operator>>(istream &input, Array &a)
{
    for (size_t i = 0; i < a.size; ++i)
        input >> a.ptr[i];

    return input; // enables cin >> x >> y;
}

ostream &operator<<(ostream &output, const Array &a )
{
    // output private ptr-based array
    for (size_t i = 0; i < a.size; ++i)
    {
        output << setw(12) << a.ptr[i];

        if ((i + 1) % 4 == 0)   // 4 numbers per row of output
            output << endl;
    }

    if (a.size % 4 != 0)       // end last line of output
        output << endl;

    return output;
}
