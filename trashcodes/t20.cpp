#include<iostream>
#include<string>
#include<array>

using namespace std;

template < typename T >

class tool
{

public:
	
	
	T getRoot (){
		return h[0];
	}

	virtual void insert( T ) =0;

	array <T , 1000 > h;
	int n = 0 ;
	
};
template < typename T >
class minheap : public tool <T>
{
public:
	virtual void insert( T input ) override
	{
		h[n] = input ;
		int x = n ;
		while ( h[(x-1)/2] > h[x] && x >=0 ){
			swap ( h[(x-1)/2] ,  h[x] );
			x = (x-1)/2;

		}
		n++;
	}
};


/*class paper : public tool
{
public:
	paper (int strnth)
		:tool (strnth)
	{
		type = 'p';
	}
	virtual bool fight (tool opponent ) const override
	{
		
		if ( opponent.gettype() == 's'){
			int x = this->strength /2 ;
			int y = opponent.getstrength()*2;
			if ( x > y )
				return true;
			else
				return false;
		}
		else {
			int x = this->strength*2;
			int y = opponent.getstrength()/2;
			if ( x > y )
				return true ;
			else
				return false;
		}
	}
	virtual void insert( T& input ) override
	{
		h[n] = input ;
		int x = n ;
		while ( b[(x-1)/2] < b[x] && x >=0 ){
			swap ( b[(x-1)/2] ,  b[x] );
			x = (x-1)/2;

		}
		n++;
	}
};
		
class scissor : public tool
{
public:
	scissor (int strnth)
		:tool (strnth)
	{
		type = 's';
	}
	virtual bool fight (tool opponent ) const override
	{
		
		if ( opponent.gettype() == 'r'){
			int x = this->strength /2 ;
			int y = opponent.getstrength()*2;
			if ( x > y )
				return true;
			else
				return false;
		}
		else {
			int x = this->strength*2;
			int y = opponent.getstrength()/2;
			if ( x > y )
				return true ;
			else
				return false;
		}
	}
};
void driver()
{
	int R,P,S;
	cin >>R >> P>> S;
	rock ROCK(R);
	paper PAPER(P);
	scissor SCISSOR(S);

	tool* r = &ROCK;
	tool* p = &PAPER;
	tool* s = &SCISSOR;
	cout << "\\\tR\tP\tS\nR\tE\t";
	if ( r->fight(*p))
		cout << "W\t";
	else 
		if ( p->fight(*r))
			cout << "L\t";
		else
			cout << "E\t";
	if ( r->fight(*s))
		cout << "W\n";
	else 
		if ( s->fight(*r))
			cout << "L\n";
		else
			cout << "E\n";
	cout << "P\t" ;

	if ( p->fight(*r))
		cout << "W\t";
	else 
		if ( r->fight(*p))
			cout << "L\t";
		else
			cout << "E\t";
	cout << "E\t" ;
	if ( p->fight(*s))
		cout << "W\n";
	else 
		if ( s->fight(*p))
			cout << "L\n";
		else
			cout << "E\n";
	cout << "S\t" ;
	if ( s->fight(*r))
		cout << "W\t";
	else 
		if ( r->fight(*s))
			cout << "L\t";
		else
			cout << "E\t";
	if ( s->fight(*p))
		cout << "W\t";
	else 
		if ( p->fight(*s))
			cout << "L\t";
		else
			cout << "E\t";
	cout << "E\n" ;
}

*/
int main()
{
		
}
