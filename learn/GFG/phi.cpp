#include<iostream>

using namespace std;
int a[] = { 1 , 2 , 4, 45, 444, 555, 666};

int bin ( int l , int r , int x)
{
    if ( l == r  )
        if ( a[l] == x)
            return l;
        else
            return -1;

    int mid = (l+r)/2;
    if ( a[mid] == x )
        return mid;
    
    if ( x > a[mid] )
        return bin( mid+1 , r , x );
    else
        return bin( l , mid-1 , x ); 
    
}
int main()
{
    cout << bin ( 0 , 6 , 634) << endl;
}