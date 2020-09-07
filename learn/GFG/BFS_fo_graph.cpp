#include<iostream>
#include<vector>
#include <bits/stdc++.h> 
using namespace std;

int main()
{
    int t;
    cin >> t;
    for ( ; t; t-- ){
        int v , u , a , b , w;
        cin >> v >> u;
        vector <int> vcts[v+1];
        int graph [v+1][v+1];
        memset( graph , 0 , sizeof( graph ));
        for ( int i = 0 ; i < u ; i++ ){
            cin >> a >> b >> w;
            vcts[a].push_back(b);
            if ( a != b )
                vcts[b].push_back(a);
            graph[a][b] = w;
            graph[b][a] = w;
        }

        bool ispicked [v+1];
        memset ( ispicked , false , sizeof (ispicked) );
        
    }
}