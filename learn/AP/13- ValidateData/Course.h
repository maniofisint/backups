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

#endif // COURSE_H_INCLUDED
