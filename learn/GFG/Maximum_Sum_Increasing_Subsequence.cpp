#include <bits/stdc++.h>

using namespace std;

int fun ( int * a , int pos)
{
    cout << pos << endl;
    int mx = 0 , sum;
    for ( int i = pos ; i < 7 ; i++ )
    {
        sum = a[i];
        int next = i +1;
        while ( next < 7 && a[i] > a[next])
            next++;
        if ( next < 7 )
            sum += fun ( a , next );
        mx = max ( mx , sum );
    }
    return mx;
}
int main()
{
    int a[] = {1, 101, 2, 3, 100, 4, 5};
    cout << fun ( a , 0 ) << endl;
}