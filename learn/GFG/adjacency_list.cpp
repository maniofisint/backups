#include <bits/stdc++.h> 
using namespace std;

int main()
{
    int t;
    cin >> t;
    for( ; t ; t-- ){
        int v , e , a , b;
        cin >> v >> e;
        vector <int> vs[v+1];
        for( int i = 0 ; i < e ; i++ ){
            cin >> a >> b ;
            vs[a].push_back(b);
            vs[b].push_back(a);
        }
    }
}
