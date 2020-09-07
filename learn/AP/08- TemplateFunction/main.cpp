#include <iostream>

using namespace std;

template <typename T>
T maximum(T m, T n, T p);

int main()
{
    int a = 2, b = 5, c = 4;

    //cin >> a >> b >> c;
    cout << "Maximum of " << a << " and " << b << " and " << c
         << " is " << maximum(a, b, c) << endl;

    float f1 = 1.5 , f2 = 5.5, f3 = 3.5;
    //cin >> f1 >> f2 >> f3;
    cout << "Maximum of " << f1 << " and " << f2 << " and " << f3
         << " is " << maximum(f1, f2, f3) << endl;

    //cout << "Maximum of " << f1 << " and " << f2 << " and " << f3
    //     << " is " << maximum(a, f2, f3) << endl;


    return 0;
}

template <typename T>
T maximum(T m, T n, T p)
{
    if(m >= n && m >= p)
        return m;
    if(n >= m && n >= p)
        return n;
    return p;
}
