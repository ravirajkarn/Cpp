#ifndef _CLUB_HPP_
#define _CLUB_HPP_

// #include <iostream>
#include <iostream>
#include <fmt/core.h>
#include <fmt/chrono.h>
#include <random>
#include <vector>

class Member
{
private:

    // static member to keep track of the number of members
    static int member_number;
    static Member* ptrBoss;
 
    // data members
    int member_id;
    std::string member_name;
    std::chrono::year_month_day dob{};
    std::string address;
    std::string telephone_number;

public:
    static void getBoss(void){
        if(ptrBoss == nullptr){
            fmt::print("\nNo boss has been appointed yet\n");
        }else{
            fmt::print("\nThe boss is: \n");
            ptrBoss->output();
        }
    }

    static void setBoss(std::vector<Member> &members){
        if(members.empty()){
            fmt::print("No members have been added yet\n");
            ptrBoss = nullptr;
            return;
        }

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(0, static_cast<int>(members.size()) - 1);
        ptrBoss = &members[static_cast<int>(dis(gen))];
    }

    Member(void);
    Member(std::chrono::year_month_day dob, std::string name, std::string address, std::string phone);
    void input(void);
    void output(void);
    ~Member();
};

int Member::member_number = 1;
Member* Member::ptrBoss = nullptr;

Member::Member(void) : member_name("Unknown"), dob(std::chrono::year_month_day{std::chrono::year{2000}, std::chrono::month{1}, std::chrono::day{1}}), address("Unknown"), telephone_number("Unknown")
{
    member_number++;
    member_id = member_number;
}

Member::Member(std::chrono::year_month_day dob, std::string name, std::string address, std::string phone)
    : member_id(++member_number), member_name(name), dob(dob), address(address), telephone_number(phone) {}

Member::~Member()
{
}

void Member::input(void){
    fmt::print("Enter the name of the member: ");
    std::getline(std::cin, member_name);
    fmt::print("Enter the date of birth of the member (yyyy-mm-dd): ");
    std::string dob_str;
    std::getline(std::cin, dob_str);
    std::istringstream ss(dob_str);
    ss >> std::chrono::parse("%Y-%m-%d", dob);
    fmt::print("Enter the address of the member: ");
    std::getline(std::cin, address);
    fmt::print("Enter the telephone number of the member: ");
    std::getline(std::cin, telephone_number);
}

void Member::output(void){
    fmt::print("\nMember ID: {}\n", member_id);
    fmt::print("Member Name: {}\n", member_name);
    fmt::print("Date of Birth: {}\n", dob);
    fmt::print("Address: {}\n", address);
    fmt::print("Telephone Number: {}\n", telephone_number);
}

#endif // end club.hpp