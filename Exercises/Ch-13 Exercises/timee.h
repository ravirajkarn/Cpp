#ifndef _TIMEE_H_
#define _TIMEE_H_

#include <time.h>

class timee
{
private:
    int Day;
    int Months;
    int Year;
public:
    void init(int months, int day, int year);
    void init(void);
    void print(void);
};
#endif //End of header file.