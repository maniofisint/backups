#include <iostream>
using namespace std;

int main()
{}

void mergSort (int * a , int l , int r)
{
    if ( l == r )
        return;

    int mid = (l + r)/2;
    int leftL = l;
    int leftR = mid;
    int rightL = mid + 1;
    int rightR = r;

    mergSort ( a , leftL , leftR );
    mergSort ( a , rightL , rightR );

    //merg part

    int left[100000];
    int right[100000];
    int i;

    //copy to another array
    
    for ( i = leftL ; i <= leftR ; i++ )
        left [i] = a[i];
    left [i+1] = a[leftR] * a [rightR] +10000;

    for ( int i = rightL ; i <= rightR ; i++ )
        right[i] = a[i];
    right [i+1] = a[leftR] * a [rightR] +10000;
    
    for ( i = l ; i <= r ; i++){

        a[i] = max (left[leftL], right[ rightL] );
        if ( a[i] == left[leftL] )
            leftL++;
        else
            rightL++;
    }
    return ;
}