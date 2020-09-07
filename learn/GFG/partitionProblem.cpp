#include <bits/stdc++.h>

using namespace std;

bool  fun ( int * a , int aSize)
{
    int sum = 0 , goal;
    for ( int i = 0 ; i < aSize ; i++ )
        sum += a[i];
    //cout << sum << endl;

    if ( sum % 2 == 1 )
        return false;

    goal = sum/2;
    set <int> dp[aSize];
    dp[0].insert(a[0]);
    for ( int i = 1 ; i < aSize ; i++ ){

        for ( auto j = dp[i-1].begin() ; j != dp[i-1].end() ; j++ )
            dp[i].insert(*j) , dp[i].insert(*j+a[i]);
        if ( dp[i].count(goal))
            return true;
    }
    return false;
}
int main()
{
    int t , n , a[200] ;
    cin >> t;
    for ( ; t ; t-- )
    {
        cin >> n;
        for ( int i = 0 ; i < n ; i++ )
            cin >> a[i];
        cout << ( fun(a,n)? "YES" : "NO" ) << endl;
    }
    
}