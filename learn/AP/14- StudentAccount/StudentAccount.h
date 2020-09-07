#ifndef STUDENTACCOUNT_H_INCLUDED
#define STUDENTACCOUNT_H_INCLUDED
#include <string>
#include <iostream>
using namespace std;

class StudentAccount
{
    public:
        StudentAccount(string stdNum, string fName = "", string lName = "");
        void setStudentNumber(string s);
        string getStudentNumber();
        void setFirstName(string s);
        string getFirstName();
        void setLastName(string s);
        string getLastName();
        void setUserName(string s);
        string getUserName();
        bool setPassword(string s);
        string getPassword();
        void printData();

    private:
        string studentNumber;
        string firstName;
        string lastName;
        string userName;
        string password;
};


#endif // STUDENTACCOUNT_H_INCLUDED
