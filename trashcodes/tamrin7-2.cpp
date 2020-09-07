#include<iostream>
#include<string>
#include<array>

using namespace std;

template < typename T >

class heap
{
public:
	virtual T getRoot() =0 ;
	virtual void  insert( T& ) =0;
protected:
	int n=0;
//	array <T,1000> h;
  	T h[1000];
};

template < typename T >
class minheap : public heap <T>
{
	private:
	T h[1000];
	int n=0;
	public:
	virtual void insert( T& input) override
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


/*class max : public heap
{
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

};*/

int main()

{

	minheap < int > ali;
	int w = 12;
	ali.insert(w);


	ali.gerRoot();
	

/*
	string s;
	cin >> s;
	if ( s == "min" ) {
		min < int > INTEGER;
		min < string > STRING; 
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
				integer.insert( inin );
			}
			if ( s == "inseertString" ){
				cin >> sin;
				str.insert (sin);
			}
			if ( s == "getRoot" ){
				cout << intrger.getRoot() << ' ' << str.getRoot() << endl;
			}
	}
	if ( s == "max" ) {
		max < int > INTEGER;
		max < string > STRING; 
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
				integer.insert( inin );
			}
			if ( s == "inseertString" ){
				cin >> sin;
				str.insert (sin);
			}
			if ( s == "getRoot" ){
				cout << intrger.getRoot() << ' ' << str.getRoot() << endl;
			}z
	}
*/
}
