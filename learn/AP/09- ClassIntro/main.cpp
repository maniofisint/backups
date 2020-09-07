#include <iostream>
#include <string>
using namespace std;

class Course
{
	public:
  		void welcomeMessage(string name)
            {
             	cout<<"Welcome to " << name << " class!" << endl;
            }
 		void welcomeMessage()
            {
             	cout<<"Welcome to " << courseName << " class!" << endl;
            }
  		void setCourseName(string s)
            {
            	courseName = s;
            }

  		string getCourseName()
            {
            	return courseName;
            }
  	private:
  		string courseName;
};

int main()
{
  	string courseName;
	Course ourClass;

  	getline(cin, courseName);
      //cin >> courseName;

  	ourClass.setCourseName(courseName);

  	ourClass.welcomeMessage(courseName);
  	ourClass.welcomeMessage();

  	cout << ourClass.getCourseName() << endl;
  	return 0;

}
