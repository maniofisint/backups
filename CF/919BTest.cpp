#include <iostream>
using namespace std;
#define siz 10
int a[siz];

int sum (int x )
{
    int out = 0 ;
    while (x>0)
    {
        out += x%10;
        x/=10;
    }
    return out;
    
}
void print ()
{
    for ( int i = 19 ; i >= 0 ; i-- )
        cout << a[i];
    cout << endl;
}
int first(int x);
int second(int& x );
int main()
{
/*
    int count = 0 , i = 0;
    while (count < 10001)
    {
        i++;
        if( sum(i) == 10 ){
            cout << i << endl;
            count++;
        }
    }
    

    int count = 1;
    int n = 70;
    a[0] = 9 ;
    a[1] = 1;
    print();
    while ( count < n ){
        while ( a[0] > 0 && a[1] < 9 ){
            a[0]--;
            a[1]++;
            count++;
            print();
        }
        if ( a[0] == 0 ){
            a[2]++;
            a[1] = 0;
            int sum = 0 ;
            for (int i = 2 ; i < siz ; i++ )
                sum += a[i];
            a[0] = 10 - sum;
            count++;
            print();
            if ( a[2] == 9 )
            {
                a[2]=0;
                a[3]++;
                a[0] = 0;
                int sum = 0 ;
                for (int i = 2 ; i < siz ; i++ )
                    sum += a[i];
                a[0] = 10 - sum;
                count++;
                print();
            }
        }
        if ( a[1] == 9 ){
            a[2]++;
            a[1] = 0;
            int sum = 0 ;
            for (int i = 2 ; i < siz ; i++ )
                sum += a[i];
            a[0] = 10 - sum;
            count++;
            print();
            if ( a[2] == 9 )
            {
                a[2]=0;
                a[3]++;
                a[0] = 0;
                int sum = 0 ;
                for (int i = 2 ; i < siz ; i++ )
                    sum += a[i];
                a[0] = 10 - sum;
                count++;
                print();
            }
        }

    }
    */

    int x = 2;
    int n = 10000;
    int y = 19;
    for ( int i = 0 ; i < n ; i++ ){
        //cout << i << ' ';
        y = first (y+1);
        int z = second(x);
        if ( y == z )
            cout << "yes" << endl;
        else{
            cout << "no " << y << ' ' << z << endl;
            break;
        }
         
    }
}

int first(int x)
{
    while ( sum (x) != 10 )
        x++;
    
    return x;
}
int second(int& x )
{
    int y = x*10 + 10-sum(x);
    x++;
    if ( sum (x) > 10 )
        while ( sum (x) > 10 )
            x++;
    return y;
}