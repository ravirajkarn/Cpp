#ifndef _DATE_HPP_
#define _DATE_HPP_

#include <fmt/chrono.h>
#include <fmt/color.h>
#include <chrono>
#include <fmt/core.h>

class DOB
{
private:
    std::chrono::year_month_day dob;
public:
    DOB(std::chrono::year_month_day dob) : dob(dob) {};
    ~DOB();
};

DOB::DOB(std::chrono::year_month_day dob)
{
}

DOB::~DOB()
{
}

#endif // Date.hpp end