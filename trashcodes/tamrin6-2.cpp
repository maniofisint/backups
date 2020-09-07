#include<iostream>
#include<string>
#include<vector>

using namespace std;

class polynomial
{
public:
	polynomial()
	{
		coeffitient.assign(1000 , 0 );
	}
	polynomial(string poly)
	{
		coeffitient.assign(1000 , 0 );
		for ( int i =0 ;i < poly.size() ; ){
			char sign;
			int cof,pow;
			if ( poly [i] == '-' || poly[i] == '+' ){
				sign = poly[i];
				i++;
				cof = 0 ;
				while (poly [i] != 'x' ){
					cof *= 10;
					cof += poly[i] - '0';
					i++;
				}
				if ( poly [i] == 'x' )
					i+=2;
				pow = 0 ;
				while ( (poly[i] !='+' && poly[i] !='-' ) && poly[i]){
					pow *= 10;
					pow += poly[i] - '0';
					i++;
				}
			degree = max ( degree , pow );
			if ( sign == '+' )
				coeffitient [pow] += cof ;
			else 
				coeffitient [pow] -=cof;
			}
		}
	}	
	polynomial operator + ( const polynomial& p )
	{
		polynomial out;
		int n = max( p.degree , this->degree );
		for ( int i =0 ;i <= n ; i++)
			out.coeffitient [i] = p.coeffitient [i] + this->coeffitient [i];
		out.degree = n;
		return out;
	}

	polynomial operator - ( const polynomial& p )
	{
		polynomial out;
		int n = max( p.degree , this->degree );
		for ( int i =0 ;i <= n ; i++)
			out.coeffitient [i] = this->coeffitient [i] - p.coeffitient [i];
		out.degree=n;
		return out;
	}
	polynomial operator * ( const polynomial& p )
	{
		polynomial out;
		int n = max( p.degree , this->degree );
		for ( int i =0 ;i <= n ; i++)
			for( int j =0 ; j <=n ;j++)
			out.coeffitient [i+j] += this->coeffitient [j] * p.coeffitient [i];
		out.degree=p.degree+this->degree;
		return out;
	}
	polynomial& operator += ( const polynomial& p )
	{
		int n = max( p.degree , this->degree );
		for ( int i =0 ;i <= n ; i++)
			this->coeffitient [i] += p.coeffitient [i];
		this->degree=n;
		return *this;
	}
	void print ()
	{
		int count = 0;
		for (int i = this->degree ; i >=0 ; i--){
			if(this->coeffitient[i] == 0 )
				continue;
			if (this->coeffitient[i] > 0)
				cout << '+' << this->coeffitient[i] << "x^" << i ;
			else 
				cout << this->coeffitient[i] << "x^" << i;
			count++;
		}
		if (count == 0 )
			cout << "+0x^0";
		cout << endl;
	}
	vector <int> coeffitient ;
	int degree=0;
};
int main ()
{
	string ONE , TWO ;
	
	cin >> ONE >> TWO ;

	polynomial one (ONE);
	polynomial two (TWO);

	string s;

	while (1){
		cin >> s;
		if (s == "+" ){
			polynomial three = one + two;
			three.print();
		}
		if (s == "-" ){
			polynomial three = one - two;
			three.print();
		}
		if (s == "*" ){
			polynomial three = one * two;
			three.print();
		}
		if (s == "exit" )
			exit(0);
	}
}
