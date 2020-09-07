#include <iostream>
#include <list>

using namespace std;
struct node
{
    int row , column;
};
class  z
{
public:
    z()
    {
        for (int i = 0 ; i < 9 ; i++ )
            IscolumnChecked [i] = 0 ;
    }
    list <node>  n;
    int IscolumnChecked [9];
};

void add ( int row , int column );
void fun (z holder  );
void print ( z holder );
int main()
{
    
    int row , column;
    cin >> row >> column;
    z holder;
    holder.IscolumnChecked[column] = 1;
    holder.n.push_back( { row , column } );
    fun ( holder );


}
void print ( z holder )
{
    for (  auto i = holder.n.begin() ; i != holder.n.end() ; i++)
    {
        node x = * i ;
        cout << x.row << ' ' << x.column << endl  ;
    }
    cout << endl ;
}
void fun (z holder  )
{

    int check = 1;
    for (int i = 1 ; i <= 8 ; i++ )
        if ( holder.IscolumnChecked[i] == 0 )
            check = 0;

    if ( check == 1 && holder.n.size() == 8){
        print( holder );
        return;
    }
    
    
    // drawing the table
    int a[9][9];
    for ( int i = 0 ; i <9 ; i++ )
        for (int j = 0 ; j < 9 ; j ++ )
            a [i][j] = 0;
        
    for (auto i = holder.n.begin() ; i!= holder.n.end() ; i++ ){
        node x = *i;
        int row = x.row;
        int column = x.column;
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
    // end of draw

    // corrnt row finde
    int correntcolumn = 0 ;
    for ( int i = 1 ; i <=8 ; i ++ )
        if ( holder.IscolumnChecked[i] == 0 ){
            correntcolumn = i;
            break;
        }
    // end of corrent row finder
    holder.IscolumnChecked[correntcolumn] = 1;
    // finding uninfected nodes and also ading them to holder

    for ( int i = 1 ; i <= 8 ; i++ ){
        if ( a[i][correntcolumn] == 0 ){
            z newholder = holder;
            node newnode = { i , correntcolumn };
            newholder.n.push_back(newnode);
            fun ( newholder );
            
            
        }
    }
    
    
        

}