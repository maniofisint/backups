#include <iostream>
#include <vector>

using namespace std;

#define siz 1000
int g[siz][siz] , mem [siz] , t ,n , m , u, v;

void clear ()
{
    for ( int i = 0 ; i < siz ; i++ ){
        mem[i] = 0;
        for ( int j = 0 ; j < siz ; j++ )
            g[i][j] = 0;
    }
}
int fun ( vector <int> path, int next )
{
    mem[next] = 1;
    for ( auto i = path.begin() ; i != path.end() ; ++ i )
        if ( next == *i )
            return 1;
    
    path.push_back(next);
    for ( int i = 0 ; i < n ; i++ )
        if ( g[next][i] == 1 )
            if ( fun ( path , i ) == 1 )
                return 1;

    return 0;

}
void printG ()
{
    for ( int i = 0 ; i < n ; i++ ){
        for ( int j = 0 ; j < n ; j++ )
            cout << g[i][j] << ' ' ;
        cout << endl;
    }
}
int main()
{
    cin >> t;
    for ( ; t > 0 ; t-- ){
        clear();
        cin >> n >> m;
        for ( int  i = 0 ; i < m ; i++ ){
            cin >> v >> u;
            g[v][u] = 1;
        }
        
        vector <int> path;
        
        int flag = 0;
        for ( int i = 0 ; i < n ; i++)
            if ( mem[i] == 0 )
                if ( fun ( path , i  ) == 1 ){
                    flag = 1;
                    break;
                }
        
        cout << flag << endl;

        

    }
}

