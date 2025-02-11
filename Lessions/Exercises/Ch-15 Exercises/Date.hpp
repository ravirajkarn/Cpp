#ifndef _DATE_HPP_
#define _DATE_HPP_

#include <fmt/chrono.h>
#include <fmt/color.h>

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

    if (months > 12 || months < 1)
    {
        fmt::print(fmt::fg(fmt::color::red),"unvalid input");
    }
    
    
    /**
     * @brief Construct a new switch object to check that days entered by the user is less the 31 days. 
     */
    switch (months)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
    // end of months
        
    default:
        break;
    }
}

DOB::~DOB()
{
}

#endif // Date.hpp end