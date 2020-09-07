#include<iostream>
using namespace std;

int main()
{
    int n,m,counter=0;
    cin >> n >> m;

    while ( n > 0 && m > 0)
    {
        if ( n == 1 && m == 1 )
            break;
        counter++;
        if ( n < m ){
            n++;
            m -= 2;
        }
        else
        {
            m++;
            n -= 2;
        }
        
    }
    cout << counter << endl;
}