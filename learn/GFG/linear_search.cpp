#include <iostream>
using namespace std;
int arr[1000000];
int main() {
	int n ;
	cin >> n;
	
	for(int i = 0 ;i < n ;i++){
		int siz,key;
		cin >> siz >> key;

		for(int i=0 ;i<siz ;i++ )
			cin >> arr[i];
		
		for(int i=0 ;i < siz ;i++)
			cout << arr[i] << ' ';
	}
}