#include<iostream>
#include<string>
#include<cmath>

using namespace std;

void fun ( int a = 48 , int b = 48 , int c = 48 )
{
    int y = (a-'0') + (b-'0')*10 + (c-'0')*100;
    if ( y % 8 == 0){
        cout << "YES\n" <<  y << endl;
        exit(0);
    }
}

int main()
{
    string in ;
    char s[200];
    cin >> in ;
    int size = in.size() , out = 0, y;

    for ( int i = 0 ; i < size ; i++ )
        s[i] = in [size-i-1];
        
    for ( int i = 0 ; i < size ; i++ )
        fun ( s[i] );

    for ( int i = 0 ; i < size -1 ; i++ )
        for (int j = i+1 ; j < size ; j++ )
            fun ( s[i] , s[j] );

    for ( int i = 0 ; i < size -2 ; i++ )
        for (int j = i+1 ; j < size -1 ; j++ )
            for (int k = j+1 ; k < size ; k++ )
                fun ( s[i] , s[j] , s[k] );

    cout << "NO" << endl;
}

