#include <iostream>

using namespace std;

int binarySearach (int * a , int l  , int r , int k );
int exponentialSearch ( int * a , int n , int k);
int main()
{
    int i = 1 , n =17; 
    for ( i = 1 ; i < n ; i*=2 )
        cout << i << endl;
}
int binarySearach (int * a , int l  , int r , int k )
{
    int mid = (l+r)/2;
    if ( a[mid] == k )
        return mid;

    if ( k > a[mid])
        return ( mid + 1 <= r )? binarySearach ( a , mid + 1 , r , k ) : -1;
    else
        return ( mid - 1 >= l )? binarySearach ( a , l , mid - l , k ) : -1;
    
}
int exponentialSearch ( int * a , int n , int k)
{
    if ( k == a[0] )
        return 0;
    int i;
    for ( i = 1 ; i < n ; i*=2){
        if ( k == a[i] )
            return i ;
        if ( k < a[i] )
            return binarySearach ( a , i/2 , i , k);
    }
    return binarySearach ( a , i , n-1 , k);
}