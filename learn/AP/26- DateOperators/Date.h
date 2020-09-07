#ifndef DATE_H
#define DATE_H
#include <iostream>

class Date
{
        friend std::ostream &operator<<(std::ostream &, const Date &);
        //friend Date operator++(Date&, int);
    public:
        Date(int m = 1, int d = 1, int y = 1900);   // default constructor
        void setDate(int, int, int);                // set month, day, year
        Date &operator++();                         // prefix increment operator
        Date operator++(int);                       // postfix increment operator
        Date &operator+=(unsigned int);             // add days, modify object
        static bool leapYear(int);                  // is date in a leap year?
        bool endOfMonth(int) const;                 // is date at the end of month?
    private:
        unsigned int month;
        unsigned int day;
        unsigned int year;

        static const int days[13];                  // days per month
        void helpIncrement();                       // utility function for incrementing date
};

#endif

