#ifndef _CLUB_HPP_
#define _CLUB_HPP_

#include <iostream>
#include <string>
#include "Date.hpp"

class Member
{
private:
    int meber_number;
    std::string member_name;
    int birthday;
    std::string address;
    std::string telephone_number;
    std::string sport_list;
    std::string fee;
public:
    Member(/* args */);
    ~Member();
};

Member::Member(/* args */)
{
}

Member::~Member()
{
}


#endif // end club.hpp
