#include<iostream>
#include<string>

using namespace std;

int main()
{
    int flag = 0 , siz;
    string s;
    cin >> s;
    siz = s.size();

    for ( int i = 0 ; i < siz ; i++ )
        if ( s[i] == 'H' || s[i] == 'Q' || s[i] == '9'  ){
            flag = 1;
            break;
        }

    if ( flag == 1 )
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}