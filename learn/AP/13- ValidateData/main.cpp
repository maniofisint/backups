#include "Course.h"

int main()
{
    string courseName;
	Course ourClass("Advanced Programing at Amirkabir Univesity of Technology", 64);
	Course otherClass("AP2");
	Course emptyClass;

  	//getline(cin, courseName);
      //cin >> courseName;

  	//ourClass.setCourseName(courseName);

  	//ourClass.welcomeMessage(courseName);
  	ourClass.welcomeMessage();


    emptyClass.setCourseName("Advanced Programing at Amirkabir Univesity of Technology");
  	cout << ourClass.getCourseName() << endl;
  	cout << ourClass.getStudentNumber() << endl;
  	cout << otherClass.getCourseName() << endl;
  	cout << otherClass.getStudentNumber() << endl;
  	cout << emptyClass.getCourseName() << endl;
  	cout << emptyClass.getStudentNumber() << endl;
  	return 0;
}
