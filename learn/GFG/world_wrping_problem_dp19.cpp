#include <bits/stdc++.h>
using namespace std;

int a[200] , dp [200] , ll , n , t;

int trt ( int x)
{
    return x*x;
}

int fun()
{
    dp[n] = -1;
    dp[n-1] = trt( ll - a[n-1] );
    int mn , i , sum ;

    for ( int j = n - 2 ; j >= 0 ; j-- )
    {
        mn = INT_MAX , i = j , sum = a[i];

        while ( sum <= ll && i < n)
        {
            mn = min ( mn , dp[i+1] + trt(ll-sum) );

            i++;
            if ( i < n )
                sum += a[i] + 1;

        }
        dp[j] = mn;
    }
    
}
void in ()
{
    cin >> n;
    for ( int i = 0 ; i < n ; i++)
        cin >> a[i];
    cin >> ll;
}
void print( int i)
{
    if ( i >= n )
        return;

    int start = i;

    while ( i < n && dp[i] < dp[i+1])
        i++;

    cout << start +1 << ' ' << i + 1  << ' ';
    
    print(i + 1 );
}
int main()
{
    cin >> t;
    for ( ; t ; t-- )
    {
        in();
        fun();
        print(0);
        cout << endl;
    }
}

/*
// recursive
int fun ( int i )
{
    //cout << i << endl;
    if ( i >= n )
        return 0;
    int mn = INT_MAX , x ,sum = a[i] , index ;
    
    while ( sum <= ll && i < n)
    {
        x = fun(i+1) + trt(ll-sum) ;
        if ( x  < mn )
            mn = x , index = i;

        i++;
        if ( i < n )
            sum += a[i] + 1;

    }
    return mn;
}
*/