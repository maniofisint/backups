#include<iostream>
#include<string>
#include <stdio.h> 
#include <stdlib.h> 
#include<time.h> 
#include<vector>
using namespace std;
int a[200000];
vector <int> check;
int n;
int different = 0 ;
int main(void) 

{
	srand(time(0));
	n = 100000;
       	check.assign( n+100 , 0);
	for(int i = 0; i<n; i++){ 
		a[i] = rand()%n;
		if (check[a[i]] == 0){
			check[a[i]]=1;
			different++;
		}
	}
 	cout << "different: " << different << endl;
//	cout << endl;
//	return 0;
/*	cin >> n;
	for(int i=0 ;i<n ;i++)
		cin >> a[i];
*/	
	int count;
	int lastCount=0;
	for(int k = 1 ; k <=n ; k++ ){
		cout << k << ':' ;
		if ( k >= different ){
			cout << 1 << ' ';
			continue;
		}
		if(lastCount == 2 ){
			cout << 2 << ' ' ;
			continue;
		}
		check.assign(n+1000 , 0 );
		int difNum = 0 ; 
		count = 1;
		for (int i = 0 ;i<n ;i++){
			if ( check[a[i]] == 0 ){
				if ( difNum == k ){
					count ++;
					check.assign(n+1000,0);
					check[a[i]] = 1;
					difNum = 1;
				}
				else{
					check[a[i]] = 1;
					difNum++;
				}
			}
		}
		lastCount = count;
		cout << count << ' ' ;
	}
	cout << endl;


} 

