#include<iostream>
#include<string>

using namespace std;
int main()
{
	string s1("happy");
	string s2(" birthday");
	string s3;

	cout << s1 << s2;
	cout << (s1==s2 ? "true" :"false")<<endl;
	cout << (s1!=s2 ? "true" :"false")<<endl;
	cout << (s1>s2 ? "true" :"false")<<endl;
	cout << (s1<s2 ? "true" :"false")<<endl;
	cout << (s1>=s2 ? "true" :"false")<<endl;
	cout << (s1<=s2 ? "true" :"false")<<endl;
	if(s3.empty())
	{
		cout << "s3 is empty" << endl;
		s3 = s1;
		cout << " s3 is = " << s3 << endl;
	}
	//cout << s1 += s2 << endl;
	s1+=s2;
	cout << s1 << endl;
	s1+="to you ";
	cout << s1 << endl;
	cout << s1.substr(1,10) << endl;
	cout << s1.substr(9) << endl;
	string s4(s1);
	cout << s4 << endl;

	try 
	{
		cout << "attempt to assign 'd' to s1.at(30) yields : " << endl;
		s1.at(30)= 'd';
	}
	catch (out_of_range &ex)
	{
		cout << "an exeption accurred: " << ex.what() << endl ;
	}
}
