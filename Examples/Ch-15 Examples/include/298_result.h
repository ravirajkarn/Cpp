// result.h
// Class Result to represent a measurement
// and the time of measurement.
// ---------------------------------------------------
#ifndef _RESULT_
#define _RESULT_
#include "284_DayTim_t.cpp" // Class DayTime

class Result
{
private:
    double val;
    DayTime time;

public:
    Result(); // Default constructor
    Result(double w, const DayTime &z = currentTime());
    Result(double w, int hr, int min, int sec);
    double getVal() const { return val; }
    void setVal(double w) { val = w; }
    const DayTime &getTime() const { return time; }
    void setTime(const DayTime &z) { time = z; }
    bool setTime(int hr, int min, int sec)
    {
        return time.setTime(hr, min, sec);
    }
    void print() const; // Output result and time.
};

Result::Result() : val(0.0){/* */};
Result::Result(double w, const DayTime &z)
    : val(w), time(z){/* */};
Result::Result(double w, int hr, int min, int sec)
    : val(w), time(hr, min, sec) { /*  */ }
#endif //  _RESULT_