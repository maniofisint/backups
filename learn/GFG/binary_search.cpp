#include <iostream>


using namespace std;

int binarySearach (int * a , int l  , int r , int k );
int main()
{
    int t,n,k,arr[1000000];

    cin >> t;
    for(int i = 0 ; i < t ; i++){
        cin >> n >> k;
        for ( int i = 0 ; i < n ; i++ )
            cin >> arr[i];
        int x =  ( binarySearach ( arr , 0 , n - 1 , k ) == -1 ) ? -1 : 1;
        cout << x << endl; 
    }
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
