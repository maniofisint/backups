#include "StudentAccount.h"

StudentAccount::StudentAccount(string stdNum, string fName, string lName)
{
    setStudentNumber(stdNum);
    setFirstName(fName);
    setLastName(lName);
    setUserName("");
    setPassword("");
}
void StudentAccount::setStudentNumber(string s)
{
    if(s.length() != 7)
        return;
    for(int i = 0; i < s.length(); i++)
        if(!isdigit(s[i]))
            return;
    studentNumber = s;
}
string StudentAccount::getStudentNumber()
{
    return studentNumber;
}
void StudentAccount::setFirstName(string s)
{
    if(s.length() <= 20)
        firstName = s;
    else
        firstName = s.substr(0, 20);
}
string StudentAccount::getFirstName()
{
    return firstName;
}
void StudentAccount::setLastName(string s)
{
    if(s.length() <= 20)
        lastName = s;
    else
        lastName = s.substr(0, 20);
}
string StudentAccount::getLastName()
{
    return lastName;
}
void StudentAccount::setUserName(string s)
{
    if(s.length() >= 20)
        s = s.substr(0, 20);
    for(int i = 0; i < s.length(); i++)
        if(!isalnum(s[i]))
            return;
    userName = s;
}
string StudentAccount::getUserName()
{
    return userName;
}
bool StudentAccount::setPassword(string s)
{
    if(s.length() < 8 || s.length() > 64)
        return false;
    bool hasLower = false, hasUpper = false,
         hasDigit = false, hasOther = false;

    for(int i = 0; i < s.length(); i++)
    {
        if(islower(s[i]))
            hasLower = true;
        else if(isupper(s[i]))
            hasUpper = true;
        else if(isdigit(s[i]))
            hasDigit = true;
        else// if(!isalnum(s[i]))
            hasOther = true;
    }
    if(hasLower && hasUpper
    && hasDigit && hasOther)
    {
        password = s;
        return true;
    }
    else
        return false;
}
string StudentAccount::getPassword()
{
    return password;
}

void StudentAccount::printData()
{
    cout << "Student Name: " << firstName << " " << lastName << endl;
    cout << "Student Number: " << studentNumber << endl;
    cout << "User Name: " << userName << endl;
    cout << "Password: " << password << endl;
}
