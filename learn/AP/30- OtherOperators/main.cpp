#include "Date.h"
int main()
{
    Date d1(4, 26, 2020);
    Date d2(19861024);
    Date d3(1, 1, 2012);
    Date d4;

    //string s = static_cast<string>(d1);
    //string s2 = d1;

    d2 = 20200101;
    d3();
    d4(1, 1, 2021);
    cout << d1 << endl;
    cout << d2 << endl;
    cout << d3 << endl;
    cout << d4 << endl;

    const char *temp = (const char *)d4;

    return 0;
}
