#include <iostream>
#include "CreateAndDestroy.h"
using namespace std;
void create();
CreateAndDestroy obj1(1, "(global auto   before main  )");
int main()
{
    cout << "MAIN FUNCTION: EXECUTION BEGINS" << endl;
    CreateAndDestroy obj2(2, "(local  auto   in     main  )");
    CreateAndDestroy obj3(3, "(local  auto   in     main  )");
    static CreateAndDestroy obj4(4, "(local  static in     main  )");

    cout << "FUNCTION CALL: CREATE" << endl;
    create();
    cout << "MAIN FUNCTION: EXECUTION RESUMES" << endl;

    CreateAndDestroy obj5(5, "(local  auto   in     main  )");

    cout << "FUNCTION CALL: CREATE" << endl;
    create();
    cout << "MAIN FUNCTION: EXECUTION RESUMES" << endl;

    cout << "MAIN FUNCTION: EXECUTION ENDS" << endl;
    return 0;
}

void create()
{
    static int n = 5;
    cout << " n = " << n << endl;
    n = 7;
    cout << "CREATE FUNCTION: EXECUTION BEGINS" << endl;
    CreateAndDestroy obj6(6, "(local  auto   in     create)");
    static CreateAndDestroy obj7(7, "(local  static in     create)");
    cout << "CREATE FUNCTION: EXECUTION ENDS" << endl;
}
