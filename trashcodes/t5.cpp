#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class phoneNumber
{
	friend ostream &operator << (ostream & , const phoneNumber &);
	friend istream &operator >> (istream & , phoneNumber &);
	private:
	string areaCode;
	string exchange;
	string line;
};

ostream &operator << (ostream & output , const phoneNumber & number)
{
	output << "(" << number.areaCode << ")"<< number.exchange << "-" << number.line;
	return output;
}

istream &operator >> (istream & input , phoneNumber & number )
{
	input.ignore();
	input >> setw(3) >> number.areaCode;
	input.ignore(2);
	input>> setw(3) >> number.exchange;
	input.ignore();
	input >> setw(4) >> number.line;
	return input;
}

int main()
{
	phoneNumber phone;
	cout << "enter" << endl;
	cin >> phone;
	cout << phone << endl;
}
