#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class pencil
{
public:
	pencil()
		:rCount(0),gCount(0),bCount(0),box(0)
	{}
	unsigned int get()	{return count;}
	friend void out (pencil a,pencil b,pencil c,string color);
	friend pencil operator + (pencil , pencil);
	friend istream operator >> (istream &  , pencil &);

private:

	static unsigned int count;
	unsigned int box;
	unsigned int rCount;
	unsigned int gCount;
	unsigned int bCount;
};
class Box
{
public:
	Box()
	:val(0)
	{}
	friend class pencil;
	unsigned int & get ()	{return val;}
	void set (int x)	{val+=x;}
private:
	unsigned int val;
	pencil p();

};

unsigned int pencil :: count = 0;

pencil operator + (pencil a,pencil b)
{
	pencil dum;
	dum.rCount=a.rCount+b.rCount;
	dum.gCount=a.gCount+b.gCount;
	dum.bCount=a.bCount+b.bCount;
	return dum;
}

void out (pencil a,pencil b,pencil c,string color)
{
	if( color == "red" )
	{
		int BOX=0,AMO=0;
		Box b[4]();
		b[a.box].p.rCount=a.rCount;
		b[b.box].p.rCount=b.rCount;
		b[c.box].p.rCount=c.rCount;
		for(int i=1 ; i<4 ;i++)
			if(b[i].p.rCount > AMO )
			{
				AMO = b[i].p.rCount;
				BOX = i;
			}
		cout << "R MAX: " << AMO << " BOX: " << BOX << endl;

	}
	if( color == "green" )
	{
		int BOX=0,AMO=0;
		Box b[4]();
		b[a.box].p.gCount=a.gCount;
		b[b.box].p.gCount=b.gCount;
		b[c.box].p.gCount=c.gCount;
		for(int i=1 ; i<4 ;i++)
			if(b[i].p.gCount > AMO )
			{
				AMO = b[i].p.gCount;
				BOX = i;
			}
		cout << "G MAX: " << AMO << " BOX: " << BOX<<endl;		
	}
	if( color == "blue" )
	{
		int BOX=0,AMO=0;
		Box b[4]();
		b[a.box].p.bCount=a.bCount;
		b[b.box].p.bCount=b.bCount;
		b[c.box].p.bCount=c.bCount;
		for(int i=1 ; i<4 ;i++)
			if(b[i].p.bCount > AMO )
			{
				AMO = b[i].pbCount;
				BOX = i;
			}
		cout << "B MAX: " << AMO << " BOX: " << BOX<< endl;	
	}
}
istream operator >> (istream & in , pencil & p)
{
	in >> p.box >> p.rCount >> p.gCount >> p.bCount;
}
int main()
{
	pencil p[3]();
	for(int i=0 ;i<3 ;i++)
		cin >> p[i];
	out (p[0],p[1],p[2],"red");
	out (p[0],p[1],p[2],"green");
	out (p[0],p[1],p[2],"blue");
