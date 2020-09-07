#include <bits/stdc++.h> 
using namespace std;

class edge 
{
public:
    int sar ,tah , vazn;
};
int parent ( int * parents , int x)
{
    if ( parents[x] == x )
        return x;
    return parent ( parents , parents[x] );
}
void uni ( int * parents , int avali , int dovomi )
{
    int x = parent ( parents , avali);
    int y = parent ( parents , dovomi );
    parents [y] = x;

}
void bubbleSort ( edge * a , int n)
{
    for ( int j = 0 ;j < n-1 ; j++ )
        for ( int i = 0 ; i < n - j - 1 ; i++ ){
            if  ( a[i].vazn > a[i+1].vazn )
                swap ( a[i], a[i+1] ); 
        }

}
void print ( edge * a , int n )
{
    for (int i = 0 ; i < n ; i++ )
        cout << a[i].sar << ' ' << a[i].tah 
        << ' ' << a[i].vazn << endl;
}
int main()
{
    int t;
    cin >> t;
    for ( ; t > 0 ; t--){
        int v,e , totalweigh = 0 , counter = 0 , parent[v+1];
        cin >> v >> e;
        edge egs[e];

        for ( int i = 1 ; i <= v ; i++ )
            parent[i] = i;

        for ( int i = 0 ; i < e ; i++ ){
            cin >> egs[i].sar >> egs[i].tah >> egs[i].vazn;
        }
        bubbleSort( egs , e );

        for( int i = 0 ; i < e ; i++ ){
            if ( parent[egs[i].sar] != parent[egs[i].tah] ){
                totalweigh += egs[i].vazn;
                uni( parent , egs[i].sar , egs[i].tah );
                counter ++ ;
                if ( counter == v-1 )break;
            }
        }
        cout << totalweigh << endl ;
    }
}