#include <bits/stdc++.h>
using namespace std;

vector <int> north = { 8, 1, 4, 3 ,5 ,2 , 6 ,7 ,19, 18, 17, 24 , 25 ,14,15 , 16 ,23 , 11,13 ,12,22, 10,9, 20,21};
vector <int> south = { 1, 2, 3, 4, 5, 6, 7, 8 , 9 , 10 , 11 , 12 ,13 , 14 ,15 ,16,17,18,19,20,21,22,23,24,25 };
#define n 25

int c = 0 , c2 = 0;

int fun ( int northL , int northR , int southL , int southR)
{
    c++;
    if ( northR < northL || southR < southL )
        return 0;

    int mx = 0 ;
    for ( int i = northL ; i <= northR ; i++ )
        for ( int j = southL ; j <= southR ; j++ )
            if ( north[i] == south[j] )
                mx = max ( mx, fun ( northL , i-1 , southR , j-1 ) +  fun ( i+1 , northR , j+1 , southR) +1 );   
    return mx;
}

int dp[n][n][n][n];
int DP ( int x1 , int x2, int x3 ,int x4 )
{
    c2++;
    if ( !( x1 <= x2 ) || !( x3 <= x4 ))
        return 0;

    if ( !( x1 >= 0 && x1 < n  &&  x2 >= 0 && x2 < n  &&  x3 >= 0 && x3 < n  &&  x4 >= 0 && x4 < n ) )
        return 0 ;
    
    return dp[x1][x2][x3][x4];
    
    
}
int fun2 ()
{
    
    for ( int northSize = 1 ; northSize <= n ; northSize++)
        for ( int southSize = 1 ; southSize <= n ; southSize++ )
            for ( int northStart = 0 ; northStart < n ; northStart++ )
                for ( int southStart = 0; southStart < n ; southStart++ )
                {
                    int northEnd = northStart + northSize -1;
                    int southEnd = southStart + southSize -1;
                    int mx = 0;
                    for ( int no = northStart ; no <= northEnd ; no++ )
                        for ( int so = southStart ; so <= southEnd ; so++ )
                            if (  south[so] == north[no] )
                                mx = max( mx , DP( northStart , no-1 , southStart , so-1 ) + DP(no+1 , northEnd , so+1 , southEnd) + 1 );

                    dp[northStart][northEnd][southStart][southEnd] = mx;
                }

    return dp[0][n-1][0][n-1];
}
int main()
{
    
    int out = fun ( 0 , north.size()-1 , 0  , south.size()-1 );
    cout << out << endl;
    cout << c << endl;
    cout << fun2() << endl;
    cout << c2 << endl;
}