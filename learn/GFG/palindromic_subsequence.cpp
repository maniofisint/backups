#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int dp [1000][1000] ;

int fun ( string &s , int l , int r)
{
    cout << l << ' ' << r << endl;
    if ( l == r )
        return 1;
    
    int mx = 0 , end ;
    for ( int i = l ; i <= r ; i++ )
    {
        end = r;
        while ( s[i] != s[end] && i <= end )
            end-- ;

        if ( dp[i+1][end-1] != -1)
            mx = max ( mx , 2 + dp[i+1][end-1] );

        else{
            if ( end > i+1 )
                mx = max ( mx , 2 + fun( s , i+1 , end-1 ));
            else if ( end == i )
                mx = max ( mx , 1 );
            else if ( end == i+1 )
                mx = max ( mx , 2 );
        }
    }   
    dp [l][r] = mx;
    return mx;
}
int main()
{
    string s = "BABCBAB";
    //dp = new int*[s.size() +100];
    //for ( int i = 0 ; i < s.size()+100 ; i++ )
    //    dp[i] = new int [s.size()+100];

    memset(dp , -1 , sizeof(dp));
    cout << dp[2][2] << endl;

    cout << fun ( s , 0 , s.size()-1 ) << endl;
}