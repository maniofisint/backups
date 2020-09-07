#include <bits/stdc++.h>
using namespace std;
class minHeap
{
    int *arr , capacity , size ;
public:
    minHeap( int capacity);
    void heapify ( int );
    int parent ( int i ) { return (i-1)/2; }
    int left ( int i ) { return i*2+1 ;}
    int right ( int i ) { return i*2+2; }
    int extractMin();
    void decreasKey ( int i , int newVal );
    int getMin () { return arr[0]; }
    void deletKey( int i );
    void insertKey( int k);  
    void heapSort( int * a );
};

minHeap :: minHeap ( int cap )
{
    size = 0;
    capacity = cap;
    arr = new int[cap];
}
void minHeap :: insertKey ( int k )
{
    if ( size = capacity ){
        cout << " fuck you ";
        return;
    }
    size ++;

    int i = size - 1;
    arr[i] = k;
    while ( arr[parent(i)] > arr[i] && i > 0 ){
        swap ( arr[i] , arr[parent(i) ] );
        i = parent(i);
    }
}
void minHeap :: decreasKey ( int i , int newVal )
{
    arr[i] = newVal;
    while ( arr [i] < arr[parent(i)] && i > 0 )
    {
        swap ( arr[i] , arr[parent(i)] );
        i = parent(i);
    }
    
}
int minHeap :: extractMin ()
{
    if ( size <= 0 )
        return INT_MAX;
    if ( size == 1 ){
        size = 0;
        return arr[0];
    }

    int root = arr[0];
    arr[0] = arr[size -1];
    size--;
    heapify(0);
    return root;
}
void minHeap :: deleteKey ( int i )
{
    decreasekey( i , INT_MIN);
    extractMin();
}
void minHeap ::heapify (int i)
{
    int l = left(i) , r = right(i) , smallest = i;
    if ( l < size && arr[l] < arr[smallest] )
        smallest = l;
    if ( r < size && arr[r] < arr[smallest] )
        smallest = r;
    if ( smallest != i ){
        swap( arr[i] , arr[smallest] );
        heapify ( smallest );
    }

}
void minHeap :: heapSort ( int * a )
{
    for ( int i = 0 ; i < size ; i++ )
        a[i] = extractMin();
    // or 
    /*
    for ( int i = 0 ; i < siz ; i++ ){
        swap( arr[0] , arr[size - 1]);
        size--;
        heapify(0);
    }
    */
}