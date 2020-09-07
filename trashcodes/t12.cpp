#include<string>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
void fun(string s,char i,int count)
{
	if(count > 5)
		return;
	string hold=s;
	s+=i;
	s+=hold;
	cout << s<<endl;
	fun(s,i+1,count+1);
}
class loc
{
public:
	int left,right,size;
};
void print(loc x)
{
	cout <<"left: " << x.left << " right: " << x.right << " size: " << x.size<< endl;
}
loc location(loc x)

{
	int mid=pow(2,x.size);
	if(x.left <= mid && mid <= x.right)
	{
		return x;
	}
	if(x.right < mid )
	{
		x.size--;
		x=location(x);
		return x;
	}
	if(mid < x.left)
	{
		x.size--;
		x.left-=mid;
		x.right-=mid;	
		x=location(x);
		return x;
	}
}
int MAX (int a,int b,int c,int d,int e)
{
	a=max(a,b);
	a=max(a,c);
	a=max(a,d);
	a=max(a,e);
	return a;
}



int main()
{
	fun("a",'b',0);
	loc f={3,6,29};
	loc g={1,2,29};
	g=location (g);
	f=location (f);
	//int x= function (g,f);
	print(f);
	print(g);
	print({1,2,3});
}

