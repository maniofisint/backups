#include <string>
#include <iostream>

using namespace std;

int t=1;
int n,k;
int a[200000];
int count =0 ;
int holder1[200000];
int holder2[200000];
void print()
{
	for(int i=0 ;i < n ;i++)
		cout << a[i] << ' ' ;
	cout << endl;
}
void fun (int l,int r)
{
//	cout << t << endl;
//	cout << "l: " << l <<" r: " <<r<<endl;
	if ( t >= k )
		return;
	if (r <= l+1 )
		return;

//	print();

	int mid = (r+l)/2;
//	cout << "mid : " <<mid << endl;

	if ( a[mid-1] < a[mid]){
		swap(a[mid-1],a[mid]);
		t+=2;
	}

	if ( t >= k )
		return;
	fun(l,mid);
	if ( t >= k )
		return;
	fun(mid,r);




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
	cin >> n >> k;
	for( int i=0 ; i<n ; i++ )
		a[i]=i+1;

	

	fun(0,n);
//	print();
//	sort(0,n);
//	cout << "count : " << count << endl;
	if (t == k )
		print();
	else
	cout << -1 << endl;
}


