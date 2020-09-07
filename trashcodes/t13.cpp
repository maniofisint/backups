#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;
int out =0 ;

void func(string s,char i,int count)//to print refrence strings
{
	if(count > 5)
		return;
	string hold=s;
	s+=i;
	s+=hold;
	cout << s<<endl;
	func(s,i+1,count+1);
}

class loc 
{
public:
	int left,right,size;
};

void print (loc x)
{
cout << "left: " << x.left <<" right: "<< x.right<<" size: "<<x.size<<endl;
}

loc location (loc x)
{
	int mid = pow ( 2, x.size );
	if ( x.left <= mid && mid <= x.right )
		return x;

	if ( x.right < mid ){
		x.size--;
		x = location (x);
		return x;
	}

	if ( mid < x.left ){
		x.size--;
		x.left-=mid;
		x.right -= mid;
		x=location (x);
		return x;
	}

}

loc left_substring(loc x)
{
	int mid = pow(2,x.size);
	loc v;
	if (x.left < mid )
		return location ( { x.left , mid-1 , x.size } );
}

loc right_substring(loc x)
{
	int mid = pow (2,x.size);
	return location ( {1 , x.right - mid , x.size} );
}
int left_size(loc x)
{
	return pow(2,x.size)-x.left;
}
int right_size(loc x)
{
	return x.right - pow(2,x.size);
}


int fun (loc a , loc b )
{
	static int guard = 0 ;
	guard ++ ;
	if ( guard > 500000 )
		return 0;

	if ( a.left == b.left && a.right == b.right )
		out = max( out , a.right - a.left +1);


	if ( a.size == b.size ){
		
		int mid = pow ( 2, a.size );

		int l = min ( a.right , b.right ) - max (a.left , b.left )+1;
//		cout << "l: " << l << endl;
		out = max (out , l);


		if ( right_size(a) > out &&  left_size(b)> out )
			fun ( right_substring(a) , left_substring(b)) ;

		if ( right_size(b) > out &&  left_size(a)> out )
			fun ( right_substring(b) , left_substring(a)) ;


	}
	else{
		if(a.size > b.size){

			int mid = pow(2,a.size);
			
			if (right_size(a) > out )
				fun( b , right_substring(a));

			if (left_size(a) > out )
				fun( b , left_substring(a));

		}
		else{
			int mid = pow(2,b.size);

			if (right_size(b) > out )
				fun( a , right_substring(b));

			if (left_size(b) > out )
				fun( a , left_substring(b));

		}
	}
	return 0;

}



int main()
{
	//func("a",'b',2);
	int a[4];
	for (int i=0 ;i<4 ;i++)
		cin >> a[i];

	loc c =location( { a[0], a[1], 29 } );
	loc b =location( { a[2], a[3], 29 } );
//	cout << right_size(c) << endl;
//	cout << right_size(b) << endl;
//	cout << left_size(c) << endl;
//	cout << left_size(b) << endl;
//	print (c);
//	print (b);
 	fun (c,b);
	cout << out << endl;
}

