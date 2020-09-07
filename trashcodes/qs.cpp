#include <bits/stdc++.h>

using namespace std ;

void delet ( int row , int column );
void add ( int row , int column );
void print();
void printNods ();


int a[100][100];
list <int> rows;
list <int> columns;
int main()
{
    while (1)
    {
        char  x;
        cin >> x;
        if ( x == 'e' )
            exit(0);
        if ( x == 'a' ){
            int row , column;
            cin >> row >> column;
            add ( row , column );
            rows.push_back(row);
            columns.push_back(column);
            print();
        }
        if ( x == 'd' ){
            int row , column;
            cin >> row >> column;
            delet ( row , column );
            print();
        }
        if ( x == 'p' )
            print();

        if ( x == 'n' )
            printNods();
    }
    

}
void add ( int row , int column )
{
    
    for ( int i = 1  ; i <= 8 ; i++ )
    {
        a[row][i] = 1;
        a[i][column] = 1;
    }
    int is[] = { 1,1,-1,-1};
    int js[] = { 1,-1,1,-1};

    for ( int s = 0 ; s < 4 ; s++){
        int i = row;
        int j = column;

        while ( i <= 8 && j<= 8 && i>=1 && j>=1 ){
            a[i][j] = 1;
            i+= is[s];
            j+= js[s];
        }
    
    }
}
void delet ( int row , int column )
{
    for ( int i = 1 ; i <= 8 ; i++ )
        for ( int j = 1 ; j <= 8 ; j++ )
            a[i][j] = 0;

    /*sdstd::list <int> :: iterator i,j;
    i= rows.begin();
    j= columns.begin();

    while ( i != rows.end() && j!= columns.end()) {
        if ( *i == row && *j == column ){
            rows.erase(i);
            columns.erase(j);
        }
        i++;
        j++;
    } 
    j = columns.begin();
    i = rows.begin();

    while ( i != rows.end() && j!= columns.end()) {
        add ( *i , *j );
        i++;
        j++;
    }*/
}
void print()
{
    cout << "   ";
    for (int i = 1 ; i <= 8 ; i++ )
        cout << i << ' ';
    cout << endl;
    for ( int i = 1 ; i <= 8 ; i++){
        cout << i << ": " ;
        for ( int j = 1; j<= 8 ; j++ )
            cout << a[i][j]<< ' '; 
        cout << endl;
    }
}
void printNods ()
{
    auto j = columns.begin();
    auto i = rows.begin();

    while ( i != rows.end() && j!= columns.end()) {
        cout << *i << " " << *j << ' ' << endl; 
        i++;
        j++;
    } 
}