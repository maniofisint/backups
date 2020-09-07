#include <bits/stdc++.h> 
using namespace std;


int main()
{
    int t ;
    cin >> t;
    for ( ; t  ; t -- ){
        int v , e , counter = 0 , sar , tah , vazn ;
        cin >> v >> e;
        bool included [v+1] ;
        int keyVal [v+1], graph[v+1][v+1];
        vector <int> vs[v+1];
        
        memset ( graph , 0 , sizeof(graph) );
        memset ( included , false , sizeof(included) );
        memset ( keyVal , INT_MAX , sizeof(keyVal) );
        
        for ( int i = 0 ; i < e ; i++ ){
            cin >> sar >> tah >> vazn;
            graph[sar][tah] = vazn;
            graph[tah][sar] = vazn;
            vs[sar].push_back(tah);
            vs[tah].push_back(sar);
        }

        keyVal[1] = 0;

        while ( counter < v ){

            int minIndex = 1 , mn = INT_MAX;
            for ( int i = 1 ; i <= v ; i++ )
                if ( keyVal[i] < mn && included[i] == false )
                    minIndex = i , mn = keyVal[i];

            included [minIndex] = true;

            for ( auto i = vs[minIndex].begin() ; i!= vs[minIndex].end() ; i++ ){
                keyVal[*i] = min ( keyVal[*i] , keyVal[minIndex] + graph[minIndex][*i] );
                
            counter++ ;
            }

        }
        for ( int i : keyVal )
            cout << i << ' ' ;
        cout << endl;
    }
}