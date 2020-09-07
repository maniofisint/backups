#include <iostream>
#include "Date.h"

using namespace std;

int main()
{
    int *p = new int(16);
    //cin >> *p;
    cout << "Array size is " << *p << endl;
    int *arr = new int[*p];

    for(int i = 0, b = 1; i < *p; i++, b *= 2)
        arr[i] = b;

    for(int i = 0; i < *p; i++)
        cout << arr[i] << ", ";
    cout << endl;

    delete p;
    delete[] arr;

    Date d1(4, 21, 2020);
    Date *d2 = new Date(3, 20, 2020);
    Date *dateArray = new Date[5];

    //dateArray[0].year = 2012;
    //dateArray[0].month = 7;
    //dateArray[0].day = 15;

    delete[] dateArray;
    delete d2;
    return 0;
}
