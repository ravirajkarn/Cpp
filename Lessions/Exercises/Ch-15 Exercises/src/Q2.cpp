/**
 * @file Q2.cpp
 * @author Sumit Kumar (ravirajkarn+support@outlook.com)
 * @brief Exercise 2
 * A sports club needs a program to manage its members.Your task is to define
 * and test a class called Member for this purpose.
 * ~■ Define the Member class using the data members shown opposite. Use
 * the Date class defined in the last chapter for your definition. Since a
 * member’s birthday will not change, the data member for birthdays must
 * be defined as a const.
 * Overload the constructor to allow for entering a date as an object as
 * well as three values for day, month, and year.
 * ~■ Implement the necessary methods.
 * ■ Test the new Member class by creating at least two objects with the data
 * of your choice and calling the methods you defined.
 * ~■ Add a static member called ptrBoss to the class.This pointer indicates
 * the member who has been appointed as chairperson. If no chairperson
 * has been appointed, the pointer should point to NULL.
 * ~■ Additionally, define the static access methods getBoss() and setBoss().
 * Use a pointer to set and return the object in question.
 * ~■ Test the enhanced Member class by reading the number of an existing
 * member, making the member the new chairperson and displaying the
 * chairperson using getBoss().
 * @version 0.1
 * @date 2024-07-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */

 #include "club.hpp"

 int main()
{
    std::vector<Member> members;

    members.push_back(Member(std::chrono::year_month_day{std::chrono::year{1990}, std::chrono::month{1}, std::chrono::day{1}}, "Sumit Kumar", "India", "1234567890"));
    members.push_back(Member(std::chrono::year_month_day{std::chrono::year{1991}, std::chrono::month{1}, std::chrono::day{1}}, "Ravi Raj Karn", "Nepal", "9876543210"));
    members.push_back(Member(std::chrono::year_month_day{std::chrono::year{1992}, std::chrono::month{1}, std::chrono::day{1}}, "Jane Doe", "USA", "5551234567"));

    members.at(0).output();
    members.at(1).output();
    members.at(2).output();

    fmt::print("\nSetting the boss\n");
    members.at(0).setBoss(members);
    members.at(0).getBoss();

    return 0;
}