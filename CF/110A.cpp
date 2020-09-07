#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    int counter = 0 ;
    cin >> s;
    int siz = s.size();

    for ( int i = 0 ; i < siz ; i++ )
        if ( s[i] == '4' || s[i] == '7' )
            counter++;
    
    if ( counter == 7 || counter == 4 )
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}