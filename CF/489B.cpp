#include <iostream>

using namespace std;
int binarySearach (int * a , int l  , int r , int k ,int asize);
void bubbleSort ( int *a , int n);

int Max [200][4] ,n , m , a[200] , b[200] ;

int main()
{
    cout << "fuck" << endl;
    cin >> n;
    for (int i = 0 ; i < n ; i++ )
        cin >> a[i];
    cin >> m;
    for (int i = 0 ; i < m ; i++ )
        cin >> b[i];

    bubbleSort ( a , n );
    bubbleSort ( b , m );
    
    
if ( n < m ){

    int x = binarySearach (a,0,n-1, a[0]-1 ,n);
    int y = binarySearach (a,0,n-1, a[0]   ,n);
    int z = binarySearach (a,0,n-1, a[0]+1 ,n);

    if ( x > 0 )
        Max[0][0] = 1;
    else
        Max[0][0] = -1;

    if ( y > 0 )
        Max[0][1] = 1;
    else
        Max[0][1] = -1;

    if ( z > 0 )
        Max[0][2] = 1;
    else
        Max[0][1] = -1;

    for ( int j = 0 ; j < 3 ; j++ )
        Max[0][3] = max ( Max[0][j] , Max[0][3] );

    int x1 = binarySearach (a,0,n-1, a[0]-1 ,n);
    int y1 = binarySearach (a,0,n-1, a[0]   ,n);
    int z1 = binarySearach (a,0,n-1, a[0]+1 ,n);

    if ( z1 > 0 )
        Max[1][2] = Max[0][3] + 1;
    else 
        Max[1][2] = -1;
    
    if ( y1 > 1 ) 
        Max[1][1] = Max[0][3] + 1;
    else {
        if ( y1 == 0 )
            Max[1][1] = -1;
        if ( y1 == 1 ){
            if ( a[0] == a[1]-1 ){

                if ( Max[0][0] != -1 )
                    Max[1][1] = Max[0][0] + 1;

                if ( Max[0][1] != -1 )
                    if ( Max[0][1] + 1 > Max[1][1] )
                        Max[1][1] = Max[0][1] + 1;

                if ( Max[0][0] == -1 && Max[0][1] == -1 )
                    Max[1][1] = Max[0][2] ;
                            
                }
            if ( a[0] <  a[1]-1 )
                Max[1][1] == Max[0][3] + 1;
        }
    }
    if ( x1 > 1)
        Max[1][0] = Max[0][3] + 1 ;
    else{
        if ( x1 == 0 )
            Max[1][0] = -1;
        else
        {
            if( a[0] <  a[1] -2 )
                Max[1][0] = Max[0][3] + 1;
            else
            {
                if( a[0] == a[1] -2 )
                    if( Max[0][0] == -1 && Max[0][1] == -1 )
                        Max[1][0] = Max[0][2];
                    else{
                        if ( Max[0][0] != -1 )
                            Max[1][0] = max( Max[0][0] + 1 ,Max[1][0] );

                        if ( Max[0][1] != -1 )
                            Max[1][0] = max( Max[0][1] + 1 ,Max[1][0] );
                    }

                if( a[0] == a[1] -1 )
                {
                    if ( Max[0][0] != -1 )
                        Max[1][0] = Max[0][0] + 1;

                    if ( Max[0][2] != -1 )
                        Max[1][0] = max( Max[0][2] + 1 , Max[1][0] );
                                
                    if ( Max[0][0] == -1 && Max[0][2] == -1)
                        Max[1][0] = Max[1][1];
                }
                        
            }
                    
                    
                    
        }
                
    }

    for ( int i = 2 ; i < n ; i++ ){
            
        int x = binarySearach (a,0,n-1, a[i]-1 ,n);
        int y = binarySearach (a,0,n-1, a[i]   ,n);
        int z = binarySearach (a,0,n-1, a[i]+1 ,n);

        //z
        if ( z > 0 )
            Max[i][2] = Max[i-1][3]+1;
        else 
            Max[i][2] = -1;
            
        //y
        if ( y > 1 ) 
            Max[i][1] = Max[i-1][3] + 1;
        else {
            if ( y == 0 )
                Max[i][1] = -1;
            if ( y == 1 ){
                if ( a[i-1] == a[i]-1 ){

                    if ( Max[i-1][0] != -1 )
                        Max[i][1] = max ( Max[i-1][0] + 1 , Max[i][1] );

                    if ( Max[i-1][1] != -1 )    
                        Max[i][1] = max ( Max[i-1][1] + 1 , Max[i][1] );

                    if ( Max[i-1][0] == -1 && Max[i-1][1] == -1 )
                        Max[i][1] = max ( Max[i-1][2] , Max[i-1][3] );
                            
                    }
                    if ( a[i-1] <  a[i]-1 )
                        Max[i][1] == Max[i-1][1]+1;
                }
            }
            //x
            if ( x > 2)
                Max[i][0] = Max[i][3] + 1 ;
            else{
                if ( x == 0 )
                    Max[i][0] = -1;
                else
                {
                    if( a[i-1] <  a[i] -2 )
                        Max[i][0] = Max[i-1][3]+1;
                    else
                    {
                        if( a[i-1] == a[i] -2 )
                            if( Max[i-1][0] == -1 && Max[i-1][1] == -1 )
                                if ( x == 1 )
                                    Max[i][0] = Max[i-1][2];
                                else if ( x == 2 )
                                    Max[i][0] = Max[i-1][2] + 1;
                            else{

                                if ( Max[i-1][0] != -1 )
                                    Max[i][0] = Max[i-1][0] + 1;

                                if ( Max[i-1][1] != -1 )
                                    if ( Max[i-1][1] + 1 > Max[i][0] )
                                        Max[i][0] = Max[i-1][1] + 1;
                            }

                        if( a[i-1] == a[i] -1 )
                            if ( a[i-2] == a[i]-2 )
                            {
                                if ( Max[i-2][0] != -1 ){
                                    if( Max[i-1][0] != -1 ){
                                        Max[i][0] = Max[i-2][0]+2;

                                    if( Max[i-1][2] != -1 ){
                                        if( Max[i-2][0] + 2 > Max[i][0] )
                                            Max[i][0] = Max[i-2][0] + 2;
                                            
                                    if( Max[i-1][2] == -1 && Max[i-1][0] == -1 )
                                        if ( Max[i-2][0] + 1 > Max[i][0] )
                                            Max[i][0] = Max[i-2][0] + 1;
                                    }

                                }
                                if ( Max[i-2][1] != -1 ){
                                    if (Max[i-1][2] != -1)
                                        Max[i][0] = Max[i-2][1] + 2;
                                    else 
                                        Max[i][0] = Max[i-2][1] + 1;
                                }
                                if ( Max[i-2][1] == -1 && Max[i-2][0] != -1 )
                                    Max[i][0] = max ( Max[i-1][0] , Max[i-1][2] ) + 1;
                            }
                            else if ( a[i-2] < a[i]-2 )
                            {
                                if ( Max[i-1][0] != -1 )
                                    Max[i][0] = Max[i-1][0] + 1;

                                if ( Max[i-1][2] != -1 )
                                    if ( Max[i-1][2] + 1 > Max[i][0] )
                                        Max[i][0] = Max[i-1][2] + 1;
                                
                                if ( Max[i-1][0] == -1 && Max[i-1][2] == -1)
                                    Max[i][0] = Max[i-1][1];
                            }
                        
                    }
                    
                    
                    
                }
                
            }

        }
        for ( int j = 0 ; j < 3 ; j++ )
            Max[i][3] = max ( Max[i][j] , Max[i][3] );
    }
}
    else
        for ( int i = 0 ; i < m ; i++ ){
            
            int x = binarySearach (b,0,n-1, b[i]-1 ,m);
            int y = binarySearach (b,0,n-1, b[i]   ,m);
            int z = binarySearach (b,0,n-1, b[i]+1 ,m);

            //z
            if ( z > 0 )
                Max[i][2] = Max[i-1][3] + 1;
            else 
                Max[i][2] = - 1;
            
            //y
            if ( y > 1 ) 
                Max[i][1] = Max[i-1][3]+1;
            else {

                if ( y == 0 )
                    Max[i][1] = -1;
                    
                if ( y == 1 ){
                    if ( a[i-1] == a[i]-1 ){

                        if ( Max[i-1][0] != -1 )
                            Max[i][1] = Max[i-1][0] + 1;

                        if ( Max[i-1][1] != -1 )
                            if ( Max[i-1][1] + 1 > Max[i][1] )
                                Max[i][1] = Max[i-1][1] + 1;

                        if ( Max[i-1][0] == -1 && Max[i-1][1] == -1 )
                            Max[i][1] = -1;
                            
                    }
                    if ( a[i-1] <  a[i]-1 )
                        Max[i][1] == Max[i-1][3] + 1;
                }
            }

            //x
            if ( x > 2)
                Max[i][0] = Max[i][3] + 1 ;
            else{
                if ( x == 0 )
                    Max[i][0] = -1;
                else
                {
                    if( a[i-1] <  a[i] -2 )
                        Max[i][0] = Max[i-1][3] + 1;
                    else
                    {
                        if( a[i-1] == a[i] -2 )
                            if( Max[i-1][0] == -1 && Max[i-1][1] == -1 )
                                if ( x == 1 )
                                    Max[i][0] = Max[i-1][2];
                                else if ( x == 2 )
                                    Max[i][0] = Max[i-1][2] + 1;
                            else{

                                if ( Max[i-1][0] != -1 )
                                    Max[i][0] = Max[i-1][0] + 1;

                                if ( Max[i-1][1] != -1 )
                                    if ( Max[i-1][1] + 1 > Max[i][0] )
                                        Max[i][0] = Max[i-1][1] + 1;
                            }

                        if( a[i-1] == a[i] -1 )
                            if ( a[i-2] == a[i]-2 )
                            {
                                if ( Max[i-2][0] != -1 ){

                                    if( Max[i-1][0] != -1 )
                                        Max[i][0] = Max[i-2][0]+2;

                                    if( Max[i-1][2] != -1 )
                                        Max[i][0] = max( Max[i-2][0] + 2 , Max[i][0] );
                                            
                                    if( Max[i-1][2] == -1 && Max[i-1][0] == -1 )
                                        Max[i][0] = max ( Max[i-2][0] + 1 , Max[i][0] );
        
                                }
                                if ( Max[i-2][1] != -1 ){

                                    if (Max[i-1][2] != -1)
                                        Max[i][0] = Max[i-2][1] + 2;
                                    else 
                                        Max[i][0] = Max[i-2][1] + 1;
                                }
                                
                                if ( Max[i-2][1] == -1 && Max[i-2][0] != -1 )
                                    Max[i][0] = max ( Max[i-1][0] , Max[i-1][2] ) + 1;
                            }
                            else if ( a[i-2] < a[i]-2 )
                            {
                                if ( Max[i-1][0] != -1 )
                                    Max[i][0] = Max[i-1][0] + 1;

                                if ( Max[i-1][2] != -1 )
                                    Max[i][0] = max( Max[i-1][2] + 1 , Max[i][0] );
                                
                                if ( Max[i-1][0] == -1 && Max[i-1][2] == -1)
                                    Max[i][0] = Max[i-1][1];
                            }
                        
                    }
                    
                    
                    
                }
                
            }
            for ( int j = 0 ; j < 3 ; j++ )
                Max[i][3] = max ( Max[i][j] , Max[i][3] );
        }
        


}
void bubbleSort ( int *a , int n)
{
    for ( int j = 0 ;j < n-1 ; j++ )
        for ( int i = 0 ; i < n - j - 1 ; i++ ){
            if  ( a[i] > a[i+1] )
                swap ( a[i], a[i+1] ); 
        }

}
int binarySearach (int * a , int l  , int r , int k , int asize )
{
    int out = 0;
    int mid = (l+r)/2;

    if ( a[mid] == k ){
        out = 1; 
        if ( mid + 1 < asize )
            for (int i = mid+1 ; a[i] == k && i < asize ; i++ )
                out ++;

        if ( mid - 1 >= 0 )
            for (int i = mid-1 ; a[i] == k && i >= 0 ; i-- )
                out ++;
        return out ;
    }
        

    if ( k > a[mid])
        return ( mid + 1 <= r )? binarySearach ( a , mid + 1 , r , k , asize ) : 0;
    else
        return ( mid - 1 >= l )? binarySearach ( a , l , mid - l , k , asize ) : 0;
    
    
}