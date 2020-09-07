#include <iostream>
//#include "Stack.h"
#include "Stack.cpp"
using namespace std;

int main()
{
    Stack<int> s;

    s.push(7);
    s.push(5);
    s.push(10);
    s.push(2);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    s.push(3);
    s.push(6);
    s.push(9);
    s.push(4);
    cout << s.pop() << endl;
    return 0;
}
