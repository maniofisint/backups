/*
 * recursive: to find biggest square starting at i,j ( top left corner ) , if matrix[i][j] == 0 biggest square is of 
 * size 0 , otherwise if matrix[i][j] == 1 biggest square starting at i,j is minimum biggest size of squares made
 * starting at i+1,j & i,j+1 & i+1,j+1 plus one  
 * dp = buttom up
 */
#include <bits/stdc++.h>
using namespace std;

#define n 5
#define m 6
int dp [n][m];
int matrix[n][m] = {{ 0, 1, 0, 1, 0, 1},
                    { 1, 0, 1, 0, 1, 0},
                    { 0, 1, 1, 1, 1, 0},
                    { 0, 0, 1, 1, 1, 0},
                    { 1, 1, 1, 1, 1, 1}};

int Min ( int x, int y, int z)
{
    return min( x, min( y, z));
}

int fun()
{
    for ( int i = 0 ; i < n ; i++)
        dp[i][m-1] = ( matrix[i][m-1] == 1)? 1 : 0;

    for ( int i = 0 ; i < m ; i++ )
        dp[n-1][i] = ( matrix[n-1][i] == 1)? 1 : 0;


    int row = n-2;
    int column = m-2;
    while ( row >= 0 || column >= 0 )
    {
        for ( int i = column ; i >= 0 ; i-- )
            if( matrix[row][i] == 0 )
                dp[row][i] = 0;
            else
                dp[row][i] = Min( dp[row+1][i], dp[row][i+1], dp[row+1][i+1] ) + 1;


        for ( int i = row ; i >= 0 ; i-- )
            if ( matrix[i][column] == 0 )
                dp[i][column] = 0;
            else
                dp[i][column] = Min ( dp[i+1][column], dp[i][column+1], dp[i+1][column+1] ) + 1;

        row--,column--;
    }

    int mx = 0;
    for ( int i = 0 ; i < n ; i++ )
        for ( int j = 0 ; j < m ; j++ )
            mx = max( mx, dp[i][j] ); 
    return mx;

}
int main()
{
    cout << fun() << endl;
}