#include "Time.h"
#include <iostream>
using namespace std;
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
