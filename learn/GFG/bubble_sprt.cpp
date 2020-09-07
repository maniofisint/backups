#include <iostream>
using namespace std;


int main()
{

}

void bubbleSort ( int *a , int n)
{
    for ( int j = 0 ;j < n-1 ; j++ )
        for ( int i = 0 ; i < n - j - 1 ; i++ ){
            if  ( a[i] > a[i+1] )
                swap ( a[i], a[i+1] ); 
        }

}