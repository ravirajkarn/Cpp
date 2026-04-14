// DayTime.h
// The class DayTime represents the time in
// hours, minutes and seconds.
// ---------------------------------------------------
#ifndef _DAYTIME_
#define _DAYTIME_

#include <ctime> // Functions time(), localtime()

class DayTime
{
private:
    short hour, minute, second;
    bool overflow;

public:
    DayTime(int h = 0, int m = 0, int s = 0)
    {
        overflow = false;
        if (!setTime(h, m, s))          // this->setTime(...)
            hour = minute = second = 0; // hour is equivalent
    } // to this->hour etc.
    bool setTime(int hour, int minute, int second = 0)
    {
        if (hour >= 0 && hour < 24 && minute >= 0 && minute < 60 && second >= 0 && second < 60)
        {
            this->hour = (short)hour;
            this->minute = (short)minute;
            this->second = (short)second;
            return true;
        }
        else
            return false;
    }
    int getHour() const { return hour; }
    int getMinute() const { return minute; }
    int getSecond() const { return second; }
    int asSeconds() const // daytime in seconds
    {
        return (60 * 60 * hour + 60 * minute + second);
    }
    bool isLess(DayTime t) const // compare *this and t
    {
        return asSeconds() < t.asSeconds();
    } // this->asSeconds() < t.asSeconds();
    // void print()
    // {
    //     ;
    // }
};

using namespace std;
const DayTime &currentTime() // Returns the
{                            // present time.
    static DayTime curTime;
    time_t sec;
    time(&sec); // Gets the present time.
    // Initializes the struct
    struct tm *time = localtime(&sec); // tm with it.
    curTime.setTime(time->tm_hour, time->tm_min,
                    time->tm_sec);
    return curTime;
}

#endif // _DAYTIME_