#include<iostream>

using namespace std;
int a[] = { 1 , 2 , 4, 45, 444, 555, 58, 666};

void merge (int l, int r)
{

}


void merge_sort (int l, int r)
{
    
    int mid = (l+r)/2;
    merge_sort ( l , mid );
    merge_sort ( mid , r );
    merge ( l , r );

}

int main()
{
    int l = 0, r = 7;
    
}