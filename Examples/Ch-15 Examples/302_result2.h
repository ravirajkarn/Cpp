// result2.h
// The class Result with a constant data member.
// ---------------------------------------------------

#ifndef _RESULT2_H_
#define _RESULT2_H_
#include "280_DayTime.h" // Class DayTime
#include <fmt/core.h>
#include <fmt/format.h>

class Result
{
private:
    double val;
    const DayTime time;

public:
    Result(double w, const DayTime &z = currentTime());
    Result(double w, int hr, int min, int sec);
    double getVal() const { return val; }
    void setVal(double w) { val = w; }
    const DayTime &getTime() const { return time; }
    void print() const;
};

Result::Result(double w, const DayTime &z)
    : val(w), time(z){/* */};
Result::Result(double w, int hr, int min, int sec)
    : val(w), time(hr, min, sec) { /*  */ }

void Result::print() const
{
    fmt::print("{0:^14} {1:^8}\n", val, time.asSeconds());
}

#endif //  _RESULT_
