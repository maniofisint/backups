#include <iostream>
#include <list>

using namespace std;

int a[5000] ,n , m , x;
void bubbleSort ( int *a , int n);

int main ()
{
  cin >> n >> m;

  for( int i = 0 ; i < m ; i ++ )
    cin >> a[i];
  
  bubbleSort ( a , m );

  int min = 1000000;
  for ( int i = 0 ; i <= m-n ; i++ )
    if ( a[i+n-1] - a[i] < min )
      min = a[i+n-1] - a[i];

  cout << min ;
}

void bubbleSort ( int *a , int n)
{
    for ( int j = 0 ;j < n-1 ; j++ )
        for ( int i = 0 ; i < n - j - 1 ; i++ ){
            if  ( a[i] > a[i+1] )
                swap ( a[i], a[i+1] ); 
        }

}