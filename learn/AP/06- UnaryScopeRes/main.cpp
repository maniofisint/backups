#include <iostream>

using namespace std;

int n;

int main()
{
    cout << n << endl;
    ++n;
    cout << n << endl;

    int n = 8;
    cout << n << endl;
    ::n++;
    ++::n;
    cout << 12 + ::n << endl;

    return 0;
}
