#include<bits/stdc++.h>
using namespace std;

#define n 10
list < pair < int , int > > l;
int dp[n];

int fun ( list< pair < int , int > > :: iterator i)
{
    if ( i == l.end() )
        return 0;
    int mx = 0;
    for ( auto j = i ; j != l.end() ; j++ )
    {
        auto k = j;
        k++;
        while ( k != l.end() && j->second >= k->first)
            k++;

        mx = max ( mx  , fun( k ) + 1 );
    }
    return mx;

}
int fun2 ()
{
    auto i = l.end();
    i--;
    int ind = l.size() - 1;

    dp[ind] = 1;
    ind--;
    i--;

    while (1)
    {
        auto nextCondidate = i ;
        i++;
        int nextIndex = ind ;
        ind++;

        while (1)
        
        // at the end
        i--;
        ind--;
    }
    

}
int main()
{
    l.push_back( make_pair( 5 , 24 ));
    l.push_back( make_pair( 39 , 60));
    l.push_back( make_pair( 27 , 40));
    l.push_back( make_pair( 15 , 28));
    l.push_back( make_pair( 50 , 90));
    l.sort();
    cout << l.size() << endl;
    cout << fun ( l.begin() ) << endl;
/*    

    for ( auto i = l.begin() ; i != l.end() ; i++ )
    {
        auto j = i;
        j++;
        while ( j != l.end() && i->second >= j->first )
            j++;

        cout << i->first << ' ' << i->second << "->" << j->first << ' ' << j->second << endl;

    }

    cout << "********" << endl;
    for ( auto se : l)
       cout << se.first << ' ' << se.second << endl;
    */
}
