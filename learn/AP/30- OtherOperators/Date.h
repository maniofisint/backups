#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <string>
using namespace std;

class Date
{
        //friend std::ostream &operator<<(std::ostream &, const Date &);
        //friend Date operator++(Date&, int);
    public:
        Date(int m, int d, int y);                  // default constructor
        Date(int = 20200101);                       // Conversion Constructor
        void setDate(int, int, int);                // set month, day, year
        Date &operator++();                         // prefix increment operator
        Date operator++(int);                       // postfix increment operator
        Date &operator+=(unsigned int);             // add days, modify object
        static bool leapYear(int);                  // is date in a leap year?
        bool endOfMonth(int) const;                 // is date at the end of month?
        //operator string () const;
        operator const char *() const;
        void operator()(int = 1, int = 1, int = 1900);
    private:
        unsigned int month;
        unsigned int day;
        unsigned int year;

        static const int days[13];                  // days per month
        void helpIncrement();                       // utility function for incrementing date
};

#endif

