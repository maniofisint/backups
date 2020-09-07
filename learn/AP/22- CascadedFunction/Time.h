#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

// Time class definition
class Time
{
    public:
        explicit Time(int = 0, int = 0, int = 0);

        // set functions
        Time setTime(int, int, int);       // set hour, minute, second
        Time setHour(int);                 // set hour (after validation)
        Time &setMinute(int);               // set minute (after validation)
        Time &setSecond(int);               // set second (after validation)

        // get functions
        unsigned int getHour() const;
        unsigned int getMinute() const;
        unsigned int getSecond() const;

        void printUniversal() const;
        void printStandard() const;
    private:
        unsigned int hour;
        unsigned int minute;
        unsigned int second;
}; // end class Time


#endif // TIME_H_INCLUDED
