#ifndef _TIMEE_H_
#define _TIMEE_H_

#include <ctime>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

// check wether the year is leap year or not.
inline bool isLeapYear(int year)
{
    return (year % 4 == 0) ? true : false;
}

class Date
{
private:
    int Day;
    int Month;
    int Year;

public:
    Date(int day, int month, int year);
    ~Date();
    void setDate(void);
    bool setDate(int mn, int da, int yr);
    int getMonth() const;
    int getDay() const;
    int getYear() const;
    bool isEqual(const Date &) const;
    bool isLess(const Date &) const;
    const string &asString() const;
    void print() const;
};

// Initialize the objects with value. Default value 01.01.01
Date::Date(int day = 1, int month = 1, int year = 1)
{
    Day = day;
    Month = month;
    Year = year;
}

// Default Destructor
Date::~Date() {}

// setDate() method without any parameters writes the current date to the object
void Date::setDate(void)
{
    time_t sec;
    time(&sec);

    this->setDate((*localtime(&sec)).tm_mon + 1, (*localtime(&sec)).tm_mday,
                  localtime(&sec)->tm_year + 1900);
}

// The methods isEqual(input) enable comparisons with a date passed to them.
// date isEqual to input
bool Date::isEqual(const Date &input) const
{
    /* my approach */
    // if (this->Year != input.getYear())
    //     return false;
    // else if (this->Month != input.getMonth())
    //     return false;
    // else if (this->Day != input.getDay())
    //     return false;
    // else
    //     return true;

    /*book solution*/
    return Month == input.Month && Day == input.Day && Year == input.Year;
}

// The methods isLess(input) enable comparisons with a date passed to them.
// date isLess then input
bool Date::isLess(const Date &input) const
{
    /* This is my approach */
    // if (this->Year < input.getYear())
    //     return true;
    // else if (this->Year == input.getYear())
    // {
    //     if (this->Month < input.getMonth())
    //         return true;
    //     else if (this->Month == input.getMonth())
    //     {
    //         if (this->Day < input.getDay())
    //             return true;
    //         else
    //             return false;
    //     }
    //     else
    //         return false;
    // }
    // else
    //     return false;
    /* This is Gemini's and Chat GPT approach*/ //~useful when data you need speed or date is large.
    // YYYYMMDD
    // int inpu = input.getYear()*10000 + input.getMonth()*100 + input.getDay();
    // int current = this->Year * 10000 + this -> Month *  100 + this -> Day;
    // return current < inpu;

    /* Book solution*/ //~best approach and useful when date is small need accuracy
    if (Year != input.Year)
        return Year < input.Year;
    else if (Month != input.Month)
        return Month < input.Month;
    else
        return Day < input.Day;
}

// getting day, months, year
int Date::getDay() const { return Day; }
int Date::getMonth() const { return Month; }
int Date::getYear() const { return Year; }

// Output reference of string in MM-DD-YYYY formate.
// e.g. 03-19-2006
const string &Date::asString() const
{
    static string result;
    stringstream data;
    data << setfill('0') << setw(2) << to_string(this->Month) << '.'
         << setw(2) << to_string(this->Day) << '.'
         << to_string(this->Year);
    data >> result;
    return result;
}

// print() outputs the date to standard output using the format Month-Day-Year.
void Date::print() const
{
    cout << "\n Today is: " << this->asString() << '\n';
}

// use to sate date just like a constructor with field check.
// months - day - year
bool Date::setDate(int mn, int da, int yr)
{

    if (mn < 1 || mn > 12)
        return false;
    if (da < 1 || da > 31)
        return false;

    switch (mn)
    {
    case 2:
        if (isLeapYear(yr))
        {
            if (da > 29)
                return false;
        }
        else if (da > 28)
            return false;
        break;
    case 1 || 3 || 5 || 7 || 8 || 10 || 12:
        if (da > 31)
            return false;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (da > 30)
            return false;
        break;
    default:
        return true;
        break;
    }

    Month = mn;
    Day = da;
    Year = yr;

    return true;
}

#endif // _TIMEE_H_