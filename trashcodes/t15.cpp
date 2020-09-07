#include <string>
#include <iostream>

using namespace std;

int a[20000];
int count =0 ;

void print(int a[],int n)
{
	for(int i=0 ;i < n ;i++)
		cout << a[i] << ' ' ;
	cout << endl;
}

bool sorted(int l ,int r )
{
	int flag = 1;
	for(int i=l ;i<r-1 ;i++)
		if (a[i] > a[i+1 ] ){
			flag = 0 ;
			break;
		}
	if ( flag == 1 )
		return true;
	return false;
}

void sort(int l , int r )
{
	count ++ ;

	if(sorted(l,r))
		return;

	int mid = (l+r)/2;
	sort(l,mid);
	sort(mid,r);

//merg part , works :)	
	int holder1[1000];
	int holder2[1000];

	int j=0;
	for(int i = l ; i <mid ;i++ ){
		holder1[j]=a[i];
		j++;
	}

	int f=0;
	for(int i=mid ;i<r ; i++ ){
		holder2[f]=a[i];
		f++;
	}

	int k = 0;
	int m = 0;
	for(int i=l ; i < r ; i++){

		if ( k >= j){ 
			a[i] = holder2[m];
			m++;
			continue;
		}
		if ( m >= f ){
			a[i] = holder1[k];
			k++;
			continue;
		}

		a[i]=min(holder1[k],holder2[m]);

		if (a[i] == holder1[k]){
			k++;
			continue;
		}
		if (a[i] == holder2[m]){
			m++;
			continue;
		}
	}
}

int main()
{
	int num;
	cin >> num;
	for(int i=0 ;i < num ;i++)
		cin >> a[i];
	sort(0,num);
	print (a,num);
	
	cout << "count : " << count <<endl;
}
