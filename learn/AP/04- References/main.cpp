#include <iostream>

using namespace std;
int square(int);
void squareByRef(int &);
int &retRefFunc(int &);

int main()
{
    int n = 16;
    int &m = n;
    int l = 32;

    cout << "m = " << m << endl;
    m = 24;
    cout << "n = " << n << endl;

    m = l;
    cout << "m = " << m << endl;

    m = 8;
    cout << "m = " << m << endl;
    cout << "n = " << n << endl;
    cout << "l = " << l << endl;

    cout << "&m = " << &m << endl;
    cout << "&n = " << &n << endl;

    cout << square(n) << endl;
    squareByRef(m);
    cout << "n = " << n << endl;

    int &r = retRefFunc(l);
    cout << "r = " << r << endl;
    l = 20;
    cout << "r = " << r << endl;

    return 0;
}

int square(int n)
{
    return n * n;
}

void squareByRef(int &r)
{
    r *= r;
}

int &retRefFunc(int &l)
{
    static int r = 18;
    //return r;
    return l;
}
