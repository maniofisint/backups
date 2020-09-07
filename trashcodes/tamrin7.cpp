#include<iostream>
#include<string>

using namespace std;

template < typename T >

class heap
{
public:
	T getRoot (){
		return h[0];
	}

	void print(){
		for(int i =0  ; i<n ;i++)
			cout << h[i] << ' ';
		cout << endl;
	}

	virtual void  insert( T& ) =0;
protected:
	int n=0;
  	T h[1000];
};

template < typename T >
class minheap : public heap <T>
{
	public:
	virtual void insert( T& input) override
	{
		heap <T> :: h[ heap <T> :: n] = input ;
		int x = heap <T> ::  n ;
		while ( heap <T> :: h[(x-1)/2] > heap <T> :: h[x] && x >=0 ){
			swap ( heap <T> :: h[(x-1)/2] ,  heap <T> :: h[x] );
			x = (x-1)/2;

		}
		heap <T> :: n++;
	}
	
};


template < typename T >
class maxheap : public heap <T>
{
	public:
	virtual void insert( T& input) override
	{
		heap <T> :: h[ heap <T> :: n] = input ;
		int x = heap <T> ::  n ;
		while ( heap <T> :: h[(x-1)/2] < heap <T> :: h[x] && x >=0 ){
			swap ( heap <T> :: h[(x-1)/2] ,  heap <T> :: h[x] );
			x = (x-1)/2;

		}
		heap <T> :: n++;
	}
	
};

int main()

{	
	string s;
	cin >> s;
	if ( s == "min" ) {
		minheap < int > INTEGER;
		minheap < string > STRING; 
		heap < int > * integer;
		heap < string > * str;
		integer = &INTEGER;
		str = &STRING;
		int inin;
		string sin;
		while (1){
			cin >> s; 
			if ( s == "insertInteger" ){
				cin >> inin;
				integer->insert( inin );
				continue;
			}
			if ( s == "insertString" ){
				getline ( cin , sin );
				str->insert (sin);
				continue;
			}
			if ( s == "getRoot" ){
				cout << integer->getRoot() << ' ' << str->getRoot() << endl;
				continue;
			}
			if (s == "exit" )
				exit(0);
		}
	}
	if ( s == "max" ) {
		maxheap < int > INTEGER;
		maxheap < string > STRING; 
		heap < int > * integer;
		heap < string > * str;
		integer = &INTEGER;
		str = &STRING;
		int inin;
		string sin;
		while (1){
			cin >> s; 
			if ( s == "insertInteger" ){
				cin >> inin;
				integer->insert( inin );
				continue;
			}
			if ( s == "insertString" ){
				getline(cin , sin);
				str->insert (sin);
				continue;
			}
			if ( s == "getRoot" ){
				cout << integer->getRoot() << ' ' << str->getRoot() << endl;
				continue;
			}
			if (s == "exit" )
				exit(0);
		}
	}

}
