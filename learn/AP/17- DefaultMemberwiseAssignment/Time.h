#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

class Time
{
    public:
        Time(int = 0, int = 0, int = 0);
        void setTime(int, int, int);
        void print();
    private:
        int hour;
        int minute;
        int second;
};

#endif // TIME_H_INCLUDED
