#include <iostream>
#include <cmath>
using namespace std ;

void heapMaker(int * a , int n);
void heapDrawer(int * a , int n);
void heapCorrector(int * a , int n);
void heapSort(int * a , int n);
void heapSort(int * a , int n);

int main()
{
    
}
void heapSort(int * a , int n)
{
    for ( int i = 0 ;i < n ; i++ )
        cout << a[i] << ' ';
    cout << endl;
}
void heapMaker( int * b , int n)
{
    for (int i = 0 ; i < n ; i++ )
    {
        int child = i;
        int parent = (i-1)/2;
        while ( b[child] > b[ parent ] ){
            swap ( b[child] , b[parent]);
            child = parent;
            parent = ( parent -1)/2;
        }
    }
}
void heapDrawer ( int * a , int n)
{
    int height = log(n)/log(2)+1;
    int lastRowLenght = pow(2,height) -1;
    int j = 1;
    int i = 0;
    for ( int k = 1 ; k <= height ; k++ )
    {
        int space = lastRowLenght / pow (2,k);
        for( int l = 0 ; l < pow ( 2, k-1 ) ; l++ ){
            for ( int m = 0 ; m < space ; m++ )
                cout << ' ';
            cout << a[i] << ' ' ;
            for ( int m = 0 ; m < space ; m++ )
                cout << ' ';
            i++;
            if ( i >= n)
                break;
        }
        cout << endl;
    }
    
}
void heapCorrector ( int * a , int n)
{
    int parent = 0;
    int firstChild = parent *2 +1;
    int secondChild = parent *2 +1;

    while ( a[parent] < a[firstChild] || a[parent] < a[secondChild] )
    {
        if ( a[parent] < a[firstChild] ){
            swap (a[parent] , a[firstChild] );
            parent = firstChild;
            firstChild = parent *2 +1;
            secondChild = parent *2 +1;
            if ( firstChild >= n)
                break;
            if ( secondChild >= n)
                secondChild = -1 ;
            continue;
        }
        if ( secondChild > 0 )
            if ( a[parent] < a[secondChild] ){
                swap (a[parent] , a[secondChild] );
                parent = secondChild;
                firstChild = parent *2 +1;
                secondChild = parent *2 +1;
            }
            if ( firstChild >= n)
                break;
            if ( secondChild >= n)
                secondChild = -1 ;
            continue;
        break;
    }
}
void heapSort(int * a , int n)
{
    heapMaker ( a , n);
    for ( int i = n- 1 ; i >0 ; i-- )
    {
        swap ( a[i] , a[0]);
        heapCorrector ( a, i+1 );
    }
}