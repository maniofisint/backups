#include<bits/stdc++.h>
using namespace std;

int lis ( int a[] , int size)
{
    int lisArr[size];
    int mx;
    for ( int i = 0 ; i < size ; i++ ){
        mx = 1;
        for ( int j = 0 ; j < i ; j++ )
            if ( a[j] < a[i] )
                mx = max ( mx , lisArr[j]+1 );
        lisArr[i] = max ( mx , lisArr[i-1]);
    }
    return lisArr[size-1];
}

int main()
{

    int a[] = {1, 11, 2, 10, 4, 5, 2, 1};
    cout << lis( a , 8) << endl;


}
