#include <iostream>
#include <iomanip>
#include "Time.h"
using namespace std;

int main()
{
	setfill('f');
    Time t1(15, 4, 12);
    Time t2(14, 64, 12);

    cout << "t1 = ";
    t1.print();

    cout << "t2 = ";
    t2.print();

    t2 = t1;
    cout << "After assignment: " << endl;
    cout << "t2 = ";
    t2.print();

    return 0;
}
Time::Time(int h, int m, int s)
{
    setTime(h, m, s);
}

void Time::setTime(int h, int m, int s)
{
    hour =   (h >= 0 && h <= 24)? h : 0;
    minute = (m >= 0 && m <= 60)? m : 0;
    second = (s >= 0 && s <= 60)? s : 0;
}

void Time::print()
{
	
    cout <<  setw(4) << hour << ":" << setw(2) << minute << ":" << setw(2) << second <<  endl;
}

