#include <iostream>
using namespace std;
void  selectionSort(int *a , int n);
int main ()
{

}

void  selectionSort(int *a , int n)
{
    for (int i = 0 ; i < n - 1 ; i++ ){
        int mn = i;
        for ( int j = i+1 ; j < n ; j++ )
            mn = ( a[j] < a[mn] ) ? j : mn;
        swap ( a[mn] , a[i] );
    }
}
