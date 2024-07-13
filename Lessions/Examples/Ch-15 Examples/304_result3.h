// result2.h
// The class Result with a constant data member.
// ---------------------------------------------------

#ifndef _RESULT3_H_
#define _RESULT3_H_

#include "280_DayTime.h" // Class DayTime
#include <fmt/core.h>
#include <fmt/format.h>

class Result
{
private:
    double val;
    const DayTime time;
    // Declaration of Static members.
    static double min, max;   // Minimum, maximum
    static bool first;        // true, if it is the first value.
    static void setMinMax(double w); // private function

public:
    Result(double w, const DayTime &z = currentTime());
    Result(double w, int hr, int min, int sec);
    double getVal() const { return val; }
    void setVal(double w) { val = w; }
    const DayTime &getTime() const { return time; }
    void print() const;
    static double getMin() { return min; }
    static double getMax() { return max; }
};

void Result::print() const
{
    fmt::print("{0:^14} {1:^8}\n", val, time.asSeconds());
}

#endif //  _RESULT_
