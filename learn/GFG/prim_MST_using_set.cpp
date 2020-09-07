#include <bits/stdc++.h>
using namespace std;

class graph
{
    int v;
    list < pair<int , int> > *adj;
public:
    graph (int v);
    void addEdge (int u, int v , int w);
    void sp ( int s);
};

graph :: graph ( int v )
{
    this-> v = v;
    adj = new list < pair < int , int > > [v];
}

void graph :: addEdge ( int u , int v , int w )
{
    adj[u].push_back( make_pair( v , w));
    adj[v].push_back( make_pair( u , w));
}

void graph :: sp ( int src )
{
    priority_queue <int , vector<int> , greater<int> > p;
    set < pair <int , int > > procced;
    vector <int> dist ( v, INT_MAX );

    procced.insert( make_pair ( 0 , src ));
    dist[src] = 0;

    while ( !procced.empty() )
    {

        pair < int , int > tmp = *( procced.begin() );
        procced.erase ( procced.begin() );

        int u = tmp.second;

        list < pair<int , int> > :: iterator i;

        for ( i = adj[u].begin() ; i != adj[u].end() ; ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;

            if ( dist[v] > dist[u] + weight )
            {
                if ( dist[v] != INT_MAX )
                    procced.erase( procced.find ( make_pair ( dist[v] , v )));
                
                dist[v] = dist[u] + weight;
                procced.insert( make_pair( dist[v] , v));
            }
        }


    }
}