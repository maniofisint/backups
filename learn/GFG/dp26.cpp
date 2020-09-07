#include <bits/stdc++.h>
using namespace std;

#define n 40
template<typename T>
void print( T s)
{
    for ( auto i : s) 
        cout << i << ' ';
    cout << endl;
}
int main()
{
    set <int> s;
    vector <int> v;
    v.assign( n+20 , 0 );
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);

    int ind = 0;
    for ( auto i : s )
    {
        v[ind] = i;
        ind++;
    }
    //print(s);
    //print(v);
    //cout << s.size() << endl;
    int x = 3;
    while ( s.size() <= n )
    {
        //cout << 1 << endl;
        for ( int i = 1 ; i <= x/2 ; i++ )
        {
            //cout << i << ' ' << x-i << ' ' << v[i] << ' ' << v[x-i] << ' ' << v[i] * v[x-i] << endl;
            s.insert( v[i] * v[x-i]);
            //v.at(s.size()-1) = *(--s.end());
            
            v.clear();
            for ( auto ind : s )
                v.push_back(ind);
            
        }
        x++;
    }
    
    print(s);
    print(v);



}

