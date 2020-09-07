#include <iostream>

using namespace std;

void man(int *q);

int main()
{
    int n = 8;
    int *p = &n;
    cout << "*p = "<< *p << endl;
    *p = 6;
    cout << "n = " << n << endl;
    man(&n);
    cout << "n = " << n << endl;
    return 0;
}

void man(int *q)
{
    *q *= 2;
}
