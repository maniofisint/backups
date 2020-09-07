#include <iostream>

using namespace std;

void increament(int &n, int d = 1);
int computeVolume(int = 1, int = 1, int = 1);

int main()
{
    int n = 5;
    cout << "n = " << n << endl;
    increament(n);
    cout << "n = " << n << endl;
    increament(n, 2);
    cout << "n = " << n << endl;
    increament(n);
    cout << "n = " << n << endl;

    int a, b, c;
    cin >> a >> b >> c;
    cout << computeVolume();
    return 0;
}

void increament(int &n, int d)
{
    n += d;
}

int computeVolume(int a, int b, int c)
{
    return a * b * c;
}
