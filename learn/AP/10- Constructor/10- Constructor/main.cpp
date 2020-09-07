#include <iostream>
#include <string>
using namespace std;

class Course
{
	public:
	    Course(string name, int n)
	    {
	        setCourseName(name);
	        studentNumber = n;
	    }
	    Course(string name)
	    {
	        setCourseName(name);
	        studentNumber = 0;
	    }
	    Course()
	    {
	        setCourseName("");
	        studentNumber = 0;
	    }
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
        void setStudentNumber(int n)
        {
            studentNumber = n;
        }

  		int getStudentNumber()
        {
            return studentNumber;
        }
  	private:
  		string courseName;
  		int    studentNumber;
};

int main()
{
  	string courseName;
	Course ourClass("AP", 64);
	Course otherClass("AP2");
	Course emptyClass;

  	//getline(cin, courseName);
      //cin >> courseName;

  	//ourClass.setCourseName(courseName);

  	//ourClass.welcomeMessage(courseName);
  	ourClass.welcomeMessage();

  	cout << ourClass.getCourseName() << endl;
  	cout << ourClass.getStudentNumber() << endl;
  	cout << otherClass.getCourseName() << endl;
  	cout << otherClass.getStudentNumber() << endl;
  	cout << emptyClass.getCourseName() << endl;
  	cout << emptyClass.getStudentNumber() << endl;
  	return 0;

}
