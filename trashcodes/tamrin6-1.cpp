#include<iostream>
#include<string>
#include<iomanip>
#include<stdexcept>

using namespace std;

class number
{
	public:
		number(string n)
		{
			if (n[0] == '-')
				throw invalid_argument("invalid input");
			else{
				int j=0;
				int in=0 ,fr=0; 

				while (n[j] != '.' && n[j]){
					in*=10;
					in+=n[j]-'0';
					i[j] = n[j];
					j++;
				}

				i[j] = 0;


				if( j < n.size() ) {
					j++;
					int fuck=j; 
					while (n[j]){
						fr*=10;
						fr+=n[j] - '0';
						f[j-fuck] = n[j];
						j++;
					}
					f[j-fuck] = 0 ;		
					j--;
					while ( f[j-fuck] == '0' && j-fuck > 0){
						f[j-fuck] = 0 ;
						j--;
					}
				}
				else{ f[0] = '0' , f[1] = 0; }


				///cout << "in: " << in << " fr: " << fr << endl;
				if (in == 0 && fr == 0 )
					throw invalid_argument("invalid input");
			}
		}

	friend ostream &operator << (ostream & , const number &);
	char i[100],f[100];


};

ostream &operator << (ostream & out , const number &num )
{
	cout << "i " << num.i <<  " f " << num.f;
}

int main()
{
	int n;
	cin >> n;
	for(int i=0 ;i < n ;i++ ){
		string s;
		cin >> s;
		try {
			number x(s);
		}
		catch ( invalid_argument &e )
		{
			cout << e.what() << endl ;
			i--;
			continue;
		}
		number x(s);
		cout << x << endl ;
	}

/*	number num("12.0100");
	cout << num << endl;

	char s[]="aloalimalai";
	cout << s << endl;
	cout << s[3] << endl;
	s[3]= '\0';
	cout << s << endl;

*/
}
