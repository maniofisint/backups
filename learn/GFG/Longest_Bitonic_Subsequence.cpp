#include <bits/stdc++.h>
using namespace std;
#define size 8

int a[] = {1, 11, 2, 10, 4, 5, 2, 1};
int lisArr[size];
int ldsArr[size];

void print( int * a , int s = 8 )
{
    for ( int i = 0 ; i < s ; i++)
        cout << a[i] << ' ';
    
    cout << endl;

}
void lis ()
{
    int mx;
    for ( int i = 0 ; i < size ; i++ ){
        mx = 1;
        for ( int j = 0 ; j < i ; j++ )
            if ( a[j] < a[i] )
                mx = max ( mx , lisArr[j]+1 );
        lisArr[i] = max ( mx , lisArr[i-1]);
    }
}
void lds()
{
    int mx;
    for ( int i = size -1 ; i >= 0 ; i-- )
    {
        mx = 1;
        for ( int j = size-1; j > i ; j-- )
            if ( a[j] < a[i] )
                mx = max ( mx , ldsArr[j]+1 );
        
        ldsArr[i] = max ( mx , ldsArr [i+1] );
    }
}

int lbs()
{
    lis();
    lds();
    print(lisArr);
    print(ldsArr);
    int mx = 0 ;
    for ( int i = 0 ; i < size ; i++ )
        mx = max ( mx , lisArr[i]+ldsArr[i]-1 );
    return mx;

}

int main()
{
    cout << lbs() << endl;
}