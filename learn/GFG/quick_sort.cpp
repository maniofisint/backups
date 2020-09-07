#include <iostream>
using namespace std;
int partition (int * a , int l , int r );
void quickSort(int * a , int l , int r);
void printArray(int * a , int  n);
int main()
{
    srand (time (NULL));
    int n = 40;
    int a[n];
    for ( int i = 0 ; i < n ; i ++ )
        a[i] = rand()%100;
    printArray(a, n);
    partition(a,0,n-1);
    printArray(a, n);
}
int partition (int * a , int l , int r )
{
    int p = r;
    int pos = l;
    while ( pos < p ){
        while ( a[pos] < a[p])
        pos++;
        if ( pos == p-1 && a[p] < a[pos] )
            swap ( a[p] , a[pos]);
        else {
            swap ( a[p] , a[p-1]);
            swap ( a[p] , a[pos]);
        }
        p--;
    }
    return p;
}
void printArray ( int * a , int n)
{
    for ( int i = 0 ; i < n ; i++)
        cout << a[i] << ' ';
    cout << endl;
}
void quickSort(int * a , int l , int r)
{
    if ( l >= r )
        return;

    int pi = partition ( a , l , r );
    quickSort ( a , l , pi-1 );
    quickSort ( a , pi+1 , r);

}
//14 42 23 6 49 41 26 3 6 64 85 25 78 76 94 40 84 98 81 31 86 64 34 69 80 8 74 24 85 41 93 52 36 16 58 85 9 84 40 16 has bug