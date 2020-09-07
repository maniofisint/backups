#include <bits/stdc++.h>
using namespace std;

#define siz 20

bool isPal[siz][siz];// if s(i,j) == a palindrom isPal[i][j] = true
int minPal[siz][siz];// minPal[i][j] = minimum number of cuts needed to make s(i,j) a palindrom
string s = "ababbbabbababawwz";
int sSize = s.size();

/*
checks if subsequence s(i,j) is palindrome or not
recursive :
    given s(i,j) , if s[i] == s[j] reuturn resault of s(i+1,j-1), else return false
dp:
    filling up isPal table by checking every subsequence of lenght l = 1 to s.size() 
    and using recursive algorithm for next step
*/
void isPalin ()
{
    memset ( isPal , false , sizeof(isPal));

    for ( int i = 0 ; i < s.size() ; i++ )
        isPal[i][i] = true;

    for ( int i = 0 ; i < s.size()-1; i++)
        if ( s[i] == s[i+1] )
            isPal[i][i+1] = true;
    
    for ( int length = 3 ; length <= s.size() ; length++ )
    {
        for ( int i = 0 ; i < s.size()-length+1 ; i++)
        {
            int end = i + length - 1;

            if ( s[i] != s[end] )
                isPal[i][end] = false;

            if ( s[i] == s[end] )
                isPal[i][end] = isPal[i+1][end-1];
            
        }
    }
}

/*
finds minimum number of cuts for s(i,j) to make each cut a palindrome
recursive:  for s(i,j) if isPal[i][j] == true , minPal[i][j] = 0 , 
            otherwise minPal[i][j] = min (minPal[i][k] + minPal[k][j] + 1) for all ( i <= k <= j)
dp =    filling up the minPal table by checking every subsequence of lenght l = 1 to s.size() 
        and using recursive algorithm for next step
dp : 
*/
int minPalin()
{
    isPalin();

    for ( int i = 0 ; i < sSize ; i++ )
        minPal[i][i] = 0;
    
    for ( int length = 2 ; length <= s.size() ; length++ )
    {
        for ( int i = 0 ; i < s.size()-length+1 ; i++)
        {
            
            int end = i + length - 1;
            if ( isPal[i][end])
                minPal[i][end] = 0;
            else{
                int mn = INT_MAX;

                for ( int j = i ; j < end ; j++ )
                    mn = min ( mn , minPal[i][j] + minPal[j+1][end] + 1);

                minPal[i][end] = mn;
            }
        }
    }
    return minPal[0][sSize-1];
    
}

int main()
{
    cout << minPalin() << endl;
}

/*
void print( )
{

    for ( int i = 0 ; i < siz ; i++){
        for ( int j = 0 ; j < siz ; j++ )
            cout << isPal[i][j] << ' ';
        cout << endl;
    }

}
void print2()
{

    for ( int i = 0 ; i < siz ; i++){
        for ( int j = 0 ; j < siz ; j++ )
            cout << minPal[i][j] << ' ';
        cout << endl;
    }
}
int fun ( int l )
{
    cout << l << endl;

    if ( isChecked[l] )
        return minPal[l];

    if ( isPal[l][sSize-1])
        return 0;

    int MIN = 1000;

    for ( int i = l ; i < sSize -1 ; i++ )
        if ( isPal [l][i] )
            MIN = min ( MIN , fun (i+1) + 1);
    
    isChecked[l] = true;
    minPal[l] = MIN;
    return MIN;
}


int fun ( int l , int r)
{
    //cout << l << ' ' << r << endl;
    //printf ( "%d %d\n",l,r);

    int mn = INT_MAX;
    if ( isPal[l][r] )
        return 0;

    for ( int i = l ; i < r ; i++ )
        mn = min ( mn , fun( l , i ) + fun ( i+1 , r ) + 1);

    return mn;
}
int isPalindrome ( string s ,int l , int r)
{
    if ( isPal[l][r] != -1 )
        return isPal[l][r];

    if ( s[l] != s[r] )
        isPal[l][r] = 0; 

    if ( r == l+1 || r == l){
        isPal[l][r] = 1;

    isPal[l][r] = isPalindrome ( s , l+1 , r-1);
    
    return isPal[l][r];
}
*/