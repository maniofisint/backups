#include <iostream>
#include <string>
#include <vector>

using namespace std;

class node
{
public:
    node ( int frq = 0 , char c = ' ')
    {
        frqnc = frq;
        ch = c;
        left = NULL;
        right = NULL;

    }
    int frqnc;
    node * left;
    node * right;
    char ch = ' ';
};

vector <node> holder;


int main ()
{
    int t;
    cin >> t ;
    for ( int i = 0 ; i < t ; i++ ){
        string in;
        cin >> in;
        int n = in.size();
        for (int i = 0 ; i < n ; i++ ){ 
            int x ;
            cin >> x;
            holder.push_back ( { x , in[i] });
        }
        for ( int j = 0 ;j < n-1 ; j++ )
            for ( int i = 0 ; i < n - j - 1 ; i++ ){
                if  ( holder[i].frqnc < holder[i+1].frqnc ){
                    node hold = holder[i];
                    holder[i] = holder [i+1];
                    holder[i+1] =  hold;
                }
            }   
        
        for (int i = 0 ; i < n ; i++ ){
            cout << holder[i].ch << ' ' << holder[i].frqnc << endl;
        }

        while ( n >= 2 ){
            node newNode ;
            newNode.frqnc = holder[ n-1 ].frqnc + holder[ n-2 ].frqnc ;
            newNode.left = &holder [ n-1 ];
            newNode.right = &holder [ n-2 ];
            holder.pop_back();
            holder.pop_back();
            
            int i = 0;

            if ( n > 1 )
                while ( i < n-1 && holder[i].frqnc > newNode.frqnc )
                    i++;

            auto j = holder.begin() + i;
            holder.emplace( j , newNode );
            n--;
            cout << endl << endl;
            for (int i = 0 ; i < n ; i++ ){
                cout << holder[i].ch << ' ' << holder[i].frqnc << endl;
            }
        }
    }
}

void print ( node * head , string cname )
{
    if ( head == NULL )
        return;

    if ( (*head).ch != ' ')
        cout << cname;


    print ( (*head).left , cname + "0" );
    print ( (*head).right , cname + "1" ); 

}

