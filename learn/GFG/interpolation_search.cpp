#include <iostream>

using namespace std;

int interpolationSearch ( int * a , int l  , int r , int k  );
int main()
{
    int n , k , arr [1000];
}

int interpolationSearch ( int * a , int l  , int r , int k )
{
    if ( k < a[r] )
     return -1;

    int mid = r + ( ( k - a[r] ) / ( a[l] - k ) ) * (l-r) ;
    if ( a[mid] == k )
        return mid;

    if ( k > a[mid])
        return ( mid + 1 <= r )? interpolationSearch ( a , mid + 1 , r , k ) : -1;
    else
        return ( mid - 1 >= l )? interpolationSearch ( a , l , mid - l , k ) : -1;
    
}