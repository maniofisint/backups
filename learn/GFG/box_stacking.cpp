#include<bits/stdc++.h>
using namespace std;

vector <int> a = {4,1,4,10};
vector <int> b = {6,2,5,12};
vector <int> c = {7,3,6,32};

int lis ( vector<int> a )
{
    int lisArr[a.size()];
    int mx;
    for ( int i = 0 ; i < a.size() ; i++ ){
        mx = 1;
        for ( int j = 0 ; j < i ; j++ )
            if ( a[j] < a[i] )
                mx = max ( mx , lisArr[j]+1 );
        lisArr[i] = max ( mx , lisArr[i-1]);
    }
    return lisArr[a.size()-1];
}

int fun ()
{
    
}
int main()
{
    array <int ,12> a;

    


}
