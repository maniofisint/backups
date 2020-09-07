#include <bits/stdc++.h>
using namespace std;

int fun ( int n , int * prices , int arrsize )
{
    if ( n <= 0 )
        return 0;

    int mx;
    for ( int i = 1 ; i < arrsize ; i++)
        mx = max ( mx , prices[i] + fun ( n - prices[i]+1, prices , arrsize ));

    return mx;
}

int main()
{
    int n = 8 ;
    int prices[] = { -1 , 1 , 5 ,8 , 9, 10 , 17 , 17 , 20 };
    
}