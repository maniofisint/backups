#include <iostream>

using namespace std;
class meeting 
{
    public:
    int start , end , num;
};
void bubbleSort ( meeting *a , int n)
{
    for ( int j = 0 ;j < n-1 ; j++ )
        for ( int i = 0 ; i < n - j - 1 ; i++ ){
            if  ( a[i].end > a[i+1].end )
                swap ( a[i], a[i+1] ); 
        }

}
void print ( meeting * a , int n )
{
    for ( int i = 0 ; i < n ; i++ )
        cout << a[i].start << ' ' << a[i].end << endl ;
}
int main()
{
    int t ;
    cin >> t;
    
    for ( ; t > 0 ; t-- ){ 
        int n , start[200], end[200];
        meeting mtngs [200];

        cin >> n;

        for ( int i = 0 ; i < n ; i++ )
            mtngs[i].num = i+1 ;

        for ( int i = 0 ; i < n ; i++ )
            cin >> mtngs[i].start ;

        for ( int i = 0 ; i < n ; i++ )
            cin >> mtngs[i].end ;

        
        bubbleSort( mtngs , n );
        int i = 0 ,tim = 0;
        while ( i < n )
        {

            while ( mtngs[i].start < tim && i < n  )
                i++;
            
            if ( i == n )
                break;
            cout << mtngs[i].num << ' ' ;
            tim = mtngs[i].end;
        }
        cout << endl;
    }
}
