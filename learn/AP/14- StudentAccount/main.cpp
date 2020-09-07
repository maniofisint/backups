#include "StudentAccount.h"

using namespace std;

int main()
{
    StudentAccount std1("9812034", "Ali", "Bateni");
    //cout << std1.getStudentNumber();
    std1.setUserName("Ali34");
    std1.setPassword("Ali2034@");
    std1.printData();
    return 0;
}
