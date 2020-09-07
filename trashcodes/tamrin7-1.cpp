#include<iostream>
#include<string>

using namespace std;


class tool
{

public:
	tool (int strnth )
		:strength(strnth)
	{}
	void setStrength(int strnth)
	{
		strength = strnth ;
	}
	int getstrength()
	{
		return strength;
	}
	char gettype()
	{
		return type;
	}
	virtual bool fight (tool* ) const = 0 ;
protected:
	int strength;
	char type;
};

class rock : public tool
{
public:
	rock (int strnth )
		:tool(strnth)
	{
		type = 'r';
	}
	virtual bool fight (tool* opponent ) const override
	{
		
		if ( opponent->gettype() == 'p'){
			double x = (double) this->strength /2 ;
			double y = (double) opponent->getstrength();
			return x > y;
		}
		if ( opponent->gettype() == 's' ){
			double x = (double) this->strength*2;
			double y = (double) opponent->getstrength();
			return x > y;
		}
	}
};


class paper : public tool
{
public:
	paper (int strnth)
		:tool (strnth)
	{
		type = 'p';
	}
	virtual bool fight (tool* opponent ) const override
	{
		
		if ( opponent->gettype() == 's'){
			double x = (double) this->strength /2 ;
			double y = (double) opponent->getstrength();
			return x > y;
		}
		if ( opponent->gettype() == 'r' ) {
			double x = (double) this->strength*2;
			double y = (double) opponent->getstrength();
			return x > y;
		}
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
	virtual bool fight (tool* opponent ) const override
	{
		
		if ( opponent->gettype() == 'r'){
			double x = (double) this->strength /2 ;
			double y = (double) opponent->getstrength();
			return x > y;
		}
		if ( opponent->gettype() == 'p' ){
			double x = (double) this->strength*2;
			double y = (double) opponent->getstrength();
			return x > y;
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
	if ( r->fight(p) )
		cout << "W\t";
	else 
		if ( p->fight(r) )
			cout << "L\t";
		else
			cout << "E\t";
	if ( r->fight(s) )
		cout << "W\n";
	else 
		if ( s->fight(r) )
			cout << "L\n";
		else
			cout << "E\n";
	cout << "P\t" ;

	if ( p->fight(r) )
		cout << "W\t";
	else 
		if ( r->fight(p) )
			cout << "L\t";
		else
			cout << "E\t";
	cout << "E\t" ;
	if ( p->fight(s) )
		cout << "W\n";
	else 
		if ( s->fight(p) )
			cout << "L\n";
		else
			cout << "E\n";
	cout << "S\t" ;
	if ( s->fight(r) )
		cout << "W\t";
	else 
		if ( r->fight(s) )
			cout << "L\t";
		else
			cout << "E\t";
	if ( s->fight(p) )
		cout << "W\t";
	else 
		if ( p->fight(s) )
			cout << "L\t";
		else
			cout << "E\t";
	cout << "E\n" ;
}


int main()
{
	driver();	
}
