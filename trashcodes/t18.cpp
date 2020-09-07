#include<iostream>
#include<string>

using namespace std;
struct array{
	int x,v;
};

array xSorted[500000];
array vSorted[500000];
int n;
bool isXsorted(int l ,int r )
{
	for(int i=l ;i<r-1 ;i++)
		if (xSorted[i].x > xSorted[i+1].x )
			return false;
	return true;
}
bool isVsorted(int l ,int r )
{
	for(int i=l ;i<r-1 ;i++)
		if (vSorted[i].v > vSorted[i+1].v )
			return false;
	return true;
}
void Xsort(int l , int r )
{
	if(isXsorted(l,r))
		return;

	int mid = (l+r)/2;
	Xsort(l,mid);
	Xsort(mid,r);

//merg part , works :)	
	array holder1[l-r+100];
	array holder2[l-r+100];

	int j=0;
	for(int i = l ; i <mid ;i++ ){
		holder1[j]=xSorted[i];
		j++;
	}

	int f=0;
	for(int i=mid ;i<r ; i++ ){
		holder2[f]=xSorted[i];
		f++;
	}

	int k = 0;
	int m = 0;
	for(int i=l ; i < r ; i++){

		if ( k >= j){ 
			xSorted[i] = holder2[m];
			m++;
			continue;
		}
		if ( m >= f ){
			xSorted[i] = holder1[k];
			k++;
			continue;
		}
		
		int Min = min ( holder1[k].x , holder2[m].x );

		if (Min == holder1[k].x){
			xSorted[i] = holder1[k];
			k++;
			continue;
		}
		if (Min == holder2[m].x){
			xSorted[i] = holder2[m];
			m++;
			continue;
		}
	}
}

void Vsort(int l , int r )
{
	if(isVsorted(l,r))
		return;

	int mid = (l+r)/2;
	Vsort(l,mid);
	Vsort(mid,r);

//merg part , works :)	
	array holder1[r-l+100];
	array holder2[r-l+100];

	int j=0;
	for(int i = l ; i <mid ;i++ ){
		holder1[j]=vSorted[i];
		j++;
	}

	int f=0;
	for(int i=mid ;i<r ; i++ ){
		holder2[f]=vSorted[i];
		f++;
	}

	int k = 0;
	int m = 0;
	for(int i=l ; i < r ; i++){

		if ( k >= j){ 
			vSorted[i] = holder2[m];
			m++;
			continue;
		}
		if ( m >= f ){
			vSorted[i] = holder1[k];
			k++;
			continue;
		}

		int Min = min ( holder1[k].v , holder2[m].v );

		if (Min == holder1[k].v){
			vSorted[i] = holder1[k];
			k++;
			continue;
		}
		if (Min == holder2[m].v){
			vSorted[i] = holder2[m];
			m++;
			continue;
		}
	}
}

void print()
{
	cout << endl;
	for (int i=0 ;i<n;i++)
		cout << xSorted[i].x<< ' ' ;
	cout << endl;

	for (int i=0 ;i<n;i++)
		cout << xSorted[i].v << ' ' ;
	cout << endl;
	
	for (int i=0 ;i<n;i++)
		cout << vSorted[i].x << ' ' ;
	cout << endl;

	for (int i=0 ;i<n;i++)
		cout << vSorted[i].v << ' ' ;
	cout << endl;
}
int main()
{
	array a = {23 , 44};
	array b = {45 , 98};
	b = a;
	cout << b.x << ' ' << b.v;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> xSorted[i].x;
		vSorted[i].x = xSorted[i].x;
	}
	for(int i=0;i<n;i++){
		cin >> xSorted[i].v;
		vSorted[i].v = xSorted[i].v;
	}

	Xsort(0,n);
	Vsort(0,n);

	print();
}
