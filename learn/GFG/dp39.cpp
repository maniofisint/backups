#include <iostream>
#include <cmath>
using namespace std;

int count = 0 ;
int fun (  int n , int sum )
{
    cout << n << ' ' << sum << endl;
    count++;
    if ( sum > pow( 10, n)-1  || sum < 0 || n < 1) 
        return 0;

    if ( n == 1 )
        return 1;

    if ( sum == 0)
        return 1;

    int Sum = 0;

    for ( int j = 1 ; j < n ; j++ )
        for ( int i = 1 ; i <= 9 ; i++ )
            if ( sum-i >= 0 )
                Sum += fun ( j , sum-i );
            else 
                break;

    //cout << "n=" << n << " sum=" << sum << ": " << Sum << endl;
    return Sum;
    

}
int main()
{
    cout << fun ( 6 , 54 ) << endl;
    cout << count << endl;
}
