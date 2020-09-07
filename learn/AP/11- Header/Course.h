#ifndef COURSE_H_INCLUDED
#define COURSE_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

class Course
{
	public:
	    Course(string name, int n);
	    Course(string name);
	    Course();
  		void welcomeMessage(string name);
 		void welcomeMessage();
  		void setCourseName(string s);
  		string getCourseName();
        void setStudentNumber(int n);
  		int getStudentNumber();
  	private:
  		string courseName;
  		int    studentNumber;
};

Course::Course(string name, int n)
{
    setCourseName(name);
    studentNumber = n;
}

Course::Course(string name)
{
    setCourseName(name);
    studentNumber = 0;
}
Course::Course()
{
    setCourseName("");
    studentNumber = 0;
}
void Course::welcomeMessage(string name)
{
    cout<<"Welcome to " << name << " class!" << endl;
}
void Course::welcomeMessage()
{
    cout<<"Welcome to " << courseName << " class!" << endl;
}
void Course::setCourseName(string s)
{
    courseName = s;
}
string Course::getCourseName()
{
    return courseName;
}
void Course::setStudentNumber(int n)
{
    studentNumber = n;
}

int Course::getStudentNumber()
{
    return studentNumber;
}

#endif // COURSE_H_INCLUDED
