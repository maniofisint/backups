#include "Course.h"

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
    if(s.length() <= 20)
        courseName = s;
    else{
        courseName = s.substr(0, 30);
    }
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
