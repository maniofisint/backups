#include <iostream>

using namespace std;

int cube(int);
float cube(float);
float cube(double);
//int cube(int &n);
int maximum(int, int);
int maximum(int, int, int);

int main()
{
    int n = 5;
    float f = 2.5;
    double lf = 1.5;
    cout << n << " ^ 3 = " << cube(n)<< endl;
    cout << f << " ^ 3 = " << cube(f)<< endl;
    cout << lf << " ^ 3 = " << cube(1.5f)<< endl;

    int a, b, c;
    cin >> a >> b;
    cout << "Maximum of " << a << " and " << b
         << " is " << maximum(a, b) << endl;
    cin >> a >> b >> c;
    cout << "Maximum of " << a << " and " << b << " and " << c
         << " is " << maximum(a, b, c) << endl;

    float f1, f2, f3;
    cin >> f1 >> f2 >> f3;
    cout << "Maximum of " << f1 << " and " << f2 << " and " << f3
         << " is " << maximum(f1, f2, f3) << endl;
    return 0;
}

int cube(int n)
{
    return n * n * n;
}

float cube(float n)
{
    return n * n * n;
}

float cube(double n)
{
    return n * n;
}

int maximum(int m, int n)
{
    if(m >= n)
        return m;
    return n;
}

int maximum(int m, int n, int p)
{
    if(m >= n && m >= p)
        return m;
    if(n >= m && n >= p)
        return n;
    return p;
}
