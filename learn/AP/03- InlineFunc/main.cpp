#include <iostream>

using namespace std;

inline int square(int n)
{
    return n * n;
}

int main()
{
    for(int i = 0; i < 10; i++)
        cout << i << " ^ 2 = " << square(i) << endl;
    return 0;
}
