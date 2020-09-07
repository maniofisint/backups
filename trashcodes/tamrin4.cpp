#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class box
{
public:
	box ()
	:r(0),g(0),b(0)
	{}
//	int get(){return val;}
	void addition(int rr,int gg,int bb)
	{
		r+=rr;
		g+=gg;
		b+=bb;
	}
	private:
		unsigned int r;
		unsigned int g;
		unsigned int b;
};

class pencil
{
public:
	void print ()
	{
		for(int i=1 ;i<4 ; i++)
			cout << B[i].get() << endl ;
		cout << count;
	}
	
	void add (int x,int r,int g,int b)
	{
		B[x].addition(r,g,b);
	}

	friend istream & operator >> (istream & , pencil &) ;
private:
	box B[4];
	
};
unsigned int pencil::count = 0 ;

istream &operator >>(istream &input , pencil &p) 
{
	int x,r,g,b;
	input >> x;
	input >> r;
	input.ignore();
	input >> g;
	input.ignore();
	input >> b;
	p.add(x,r,g,b);

}

int main()
{
	pencil A;
	for (auto i=0 ;i < 3 ;i++)
		cin >> A;
	A.print();
}
