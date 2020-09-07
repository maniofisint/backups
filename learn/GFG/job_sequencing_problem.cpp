#include <bits/stdc++.h> 
using namespace std;

class job
{
    public:
    int id , deadline , profit ;
};
void bubbleSort ( job * a , int n)
{
    for ( int j = 0 ;j < n-1 ; j++ )
        for ( int i = 0 ; i < n - j - 1 ; i++ ){
            if  ( a[i].profit < a[i+1].profit )
                swap ( a[i], a[i+1] ); 
        }

}

int main()
{
    int t;
    cin >>t;
    for ( ; t > 0 ; t-- ){
        int n , dl[900] , counter = 0 , prof = 0 , maxdl = 0 ;
        job j[900];
        cin >> n;
        for ( int i = 0 ; i < n ; i++ ){
            cin >> j[i].id >> j[i].deadline  >> j[i].profit;
            maxdl = max ( maxdl , j[i].deadline);
        }
        
        bubbleSort( j , n );
        memset( dl , 0 , sizeof( dl ));
        for ( int i = 0 ; i < n ; i++ )
        {
            int pos = j[i].deadline;
            while ( dl[pos] != 0 && pos > 0 )
                pos--;
            if ( pos > 0 ){
                dl [ pos ] = j[i].id;
                counter++;
                prof += j[i].profit;
                if ( counter == maxdl )
                    break;
            }
        }
        cout << counter << ' ' << prof << endl ;
    }
}