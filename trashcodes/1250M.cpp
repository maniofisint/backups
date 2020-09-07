#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
# define tsiz 10000
int table [tsiz][tsiz];
int siz = 0;
void print ();
void stones ();
void color (int n);
void start ();
int main()
{
    siz = 16;
    stones();
    //start();
    //color (8);
    //color (4);
    color (2);
    color (1);
    //color (7);
    print ();

}
void start ()
{
    vector <int> row;
    vector <int> column;

    for(int i = siz/2 ; i<siz ;i++)
        column.push_back(i);

    for(int i = 0 ; i<siz/2 ;i++)
        row.push_back(i);
    
    for(int i =0 ;i<row.size() ;i++)
        for(int j=0 ; j<column.size() ; j++)
            table[row[i]][column[j]] = 1;

    row.clear();
    column.clear();

    for(int i = 0 ; i<siz/2 ;i++)
        column.push_back(i);

    for(int i = siz/2+1 ; i<siz ;i++)
        row.push_back(i);
    
    for(int i =0 ;i<row.size() ;i++)
        for(int j=0 ; j<column.size() ; j++)
            table[row[i]][column[j]] = 1;

    row.clear();
    column.clear();

    for(int i = siz/4 ; i<siz/2 ;i++)
        column.push_back(i);

    for(int i = 0 ; i<siz/4 ;i++)
        row.push_back(i);

    for(int i = siz/2+1 ; i<siz ;i++)
        row.push_back(i);

    for(int i =0 ;i<row.size() ;i++)
        for(int j=0 ; j<column.size() ; j++)
            table[row[i]][column[j]] = 1;

    row.clear();
    column.clear();
    for(int i = siz/2+siz/4 ; i<siz ;i++)
        column.push_back(i);

    for(int i = 0; i<siz/2-1 ;i++)
        column.push_back(i);

    for(int i = siz/2 ; i<siz/2+siz/4 ;i++)
        row.push_back(i);
    
    for(int i =0 ;i<row.size() ;i++)
        for(int j=0 ; j<column.size() ; j++)
            table[row[i]][column[j]] = 1;

}
void color (int a)
{
    vector <int> row;
    vector <int> column;

    for(int i =0 ;i < siz ; i+=a+1 )
        for(int j =0 ; j < a ;j++)
            if ( i < siz){
                column.push_back(i);
                i++;
            }
    for(int i = a+1 ; i<siz ; i+=a+1 )
        for(int j =0 ; j < a ;j++)
            if ( i < siz){
                row.push_back(i);
                i++;
            }
    for(int i =0 ;i<row.size() ;i++)
        for(int j=0 ; j<column.size() ; j++)
            table[row[i]][column[j]] = 1;

    row.clear();
    column.clear();


    for(int i = a ; i < siz  ;i+=a+1)
        for(int j =0 ; j < a ;j++)
            if ( i < siz){
                column.push_back(i);
                i++;
            }
            
    for(int i = 0 ; i<siz ; i+=a+1 )
        for(int j =0 ; j < a ;j++)
            if ( i < siz){
                row.push_back(i);
                i++;
            }
    for(int i =0 ;i<row.size() ;i++)
        for(int j=0 ; j<column.size() ; j++)
            table[row[i]][column[j]] = 1;

    row.clear();
    column.clear();

    for(int i = 2*a ; i < siz  ;i+=a+1)
        for(int j =0 ; j < a ;j++)
            if ( i < siz){
                column.push_back(i);
                i++;
            }
            
    for(int i = a ; i<siz ; i+=a+1 )
        for(int j =0 ; j < a ;j++)
            if ( i < siz){
                row.push_back(i);
                i++;
            }
    for(int i =0 ;i<row.size() ;i++)
        for(int j=0 ; j<column.size() ; j++)
            table[row[i]][column[j]] = 1;


    /*
    for(int i = 2*a ; i < siz ; i++ ){


    }

*/




}

void print ()
{
    /*for (int i =1 ; i<=siz ;i++)
        cout << i << ' ';
    cout << endl;*/
    int Start = 0 ,end = siz+10 ;
    for (int i = Start ;i < end ; i++){
        for(int j = Start ; j< end ; j++)
            if(table [i][j] == 0 )
                cout << "_ ";
            else     
                cout << table [i][j] << ' ' ;   
        cout << endl;
    }       

}
void stones ()
{
    table [0][0]=9;
    for(int i = 1 ;i<tsiz ;i++){
        table [i][i]=9;
        table [i][i-1]=9;
    }
}