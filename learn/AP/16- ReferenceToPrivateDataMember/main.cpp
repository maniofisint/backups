#include <iostream>
#include "Time.h"
using namespace std;

int main()
{
    Time t(14, 49, 25);

    t.print();
    cout << t.getHour() << endl;
    t.getHour() = 16;
    t.print();
    int &h = t.getHour();
    h = 18;
    t.print();
    int *p = t.getHourPointer();
    *p = 20;
    t.print();
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
    cout << hour << ":" << minute << ":" << second << endl;
}

int &Time::getHour()
{
    return hour;
}

int *Time::getHourPointer()
{
    return &hour;
}
