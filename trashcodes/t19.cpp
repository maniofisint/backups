#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

int main()
{
	int a[]={8,9,5,6,3,1,21,3,4,323,4,32,324,333,56,45,3248,54,32,0};
	srand(time(0));
	int b[1000];
	b[0]=a[0];
	for(int i =1 ; i<50 ;i++)
	{
		b[i] = rand()%100;
		int x=i;
		while ( b[(x-1)/2]>b[x] && x>=0){
			swap(b[(x-1)/2],b[x]);
			x = (x-1)/2;
			}
	}

	for(int i=0 ;i < 50 ;i++ )
	cout << b[i] << ' ' ;
	cout << endl;
}
