#include <iostream>
using namespace std;

char c[200][200];

int main()
{
    int t;
    cin >> t;
    for ( ; t >0 ; t--){
        int n,m , count = 0;
        cin >> n >> m;

        for ( int i = 0 ; i < n ; i++ )
            for ( int j = 0 ; j < m ; j++ )
                cin >> c[i][j];
        
        for ( int i = 0 ; i < n ; i++ )
            if( c[i][m-1] == 'R' )
                count++;

        for ( int i = 0 ; i < m ; i++ )
            if( c[n-1][i] == 'D' )
                count++;
                 
        cout << count << endl;  
    }
}
