// const objects and const member functions.
#include "Time.h"
#include <iomanip>
#include <stdexcept>
#include <iostream>
using namespace std;

int main()
{
    Time wakeUp(6, 45, 0);     // non-constant object
    const Time noon(12, 0, 0); // constant object

    wakeUp.printStandard();
    wakeUp.printUniversal();

    cout << "Hour of noon is " << noon.getHour() << endl;
    noon.printStandard();
    noon.printUniversal();
}
Time::Time(int hour, int minute, int second)
{
   setTime(hour, minute, second);
}

void Time::setTime(int h, int m, int s)
{
   setHour(h);
   setMinute(m);
   setSecond(s);
}

void Time::setHour(int h)
{
   if (h >= 0 && h < 24)
      hour = h;
   else
      throw invalid_argument("hour must be 0-23");
}

void Time::setMinute(int m)
{
   if ( m >= 0 && m < 60 )
      minute = m;
   else
      throw invalid_argument("minute must be 0-59");
}

void Time::setSecond(int s)
{
   if ( s >= 0 && s < 60 )
      second = s;
   else
      throw invalid_argument("second must be 0-59");
}

unsigned int Time::getHour() const
{
   return hour;
}

unsigned int Time::getMinute() const
{
   return minute;
}

unsigned int Time::getSecond() const
{
   return second;
}

// print Time in universal-time format (HH:MM:SS)
void Time::printUniversal() const
{
   cout << setfill('0')
        << setw(2) << getHour() << ":"
        << setw(2) << getMinute() << ":"
        << setw(2) << getSecond() << endl;
}

// print Time in standard-time format (HH:MM:SS AM or PM)
void Time::printStandard() const
{
   cout << setfill('0')
        << setw(2) << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12) << ":"
        << setw(2) << getMinute() << ":"
        << setw(2) << getSecond()
        << (hour < 12 ? " AM" : " PM") << endl;
}
