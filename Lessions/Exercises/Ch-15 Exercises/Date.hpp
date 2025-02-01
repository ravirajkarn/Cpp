#ifndef _DATE_HPP_
#define _DATE_HPP_

#include <chrono.h>

class DOB
{
private:
    int day;
    int month;
    int year;
public:
    DOB(int date, int months, int years);
    bool leap_year(int years) {return (years%4 == 0);}
    void wdob();
    void idob();
    ~DOB();
};

/**
 * @brief DD MM YY
 * 
 * @param date DD
 * @param months MM
 * @param years YY
 */
DOB::DOB(int date, int months, int years)
{
    if

    switch (months)
    {
    case 01:
    case 03:
    case 05:
    case 07:
    case 08:
    case 10:
    case 12:
        
    default:
        break;
    }
}

DOB::~DOB()
{
}


#endif // Date.hpp end
