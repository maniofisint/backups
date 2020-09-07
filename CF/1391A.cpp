#include <iostream>
using namespace std;
int a[200];
int main()
{
    int n ;
    cin >> n;
    for ( int i = 1 ; i <= n ; i++)
        cin >> a[i];

    for ( int i = 1 ; i <= n ; i++ ){
        for ( int j = i-1; j >= 1 ; j-- )
            if ( a[j] > a[i] ){
                cout << i << ' ' << j << endl ;
                break;
            }
        for ( int j = i+1 ; j <= n ; j++ )
            if ( a[j] > a[i] ){
                cout << i << ' ' << j << endl ;
                break;
            }
    }

}


