#include <iostream>
#include <cmath>
using namespace std;
int jumpSearch( int * a , int n , int k);
int main()
{
    int n , k , arr[1000000];
    int x =4;
    cout << sqrt(x);
    for ( int i = 0 ; i < 13 ; i+= 5)
        cout << i << endl;
}
int jumpSearch( int * a , int n , int k)
{
    int m = sqrt (n);
    int j;
    for ( int i = 0 ; i < n ; i+= m)
        if ( k <=  a[i] )
            for( j = i-m ; j < i ; j++ )
                if ( k == a[j] )
                    return j;
                    
    for ( int i = j ; i < n   ; i++)
        if ( k == a[i] )
            return i;

    return -1;
}