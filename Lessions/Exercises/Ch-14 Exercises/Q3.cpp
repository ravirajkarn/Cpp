/*
Exercise 3
The Date class does not ensure that an object represents a valid date.To avoid
this issue, add range checking functionality to the class. Range checking is
performed by the constructor and the setDate() method with three
parameters.
■First, write a function called isLeapYear() that belongs to the bool
type and checks whether the year passed to it is a leap year. Define the
function as a global inline function and store it in the header file
Date.h.
■Modify the setDate() method to allow range checking for the date
passed to it.The constructor can call setDate().
■Test the new version of the Date class.To do so, and to test set-
Date(...), read a date from the keyboard.
*/

//~ This is integrated with Q2.

#include "timee.h"

using namespace std;
int main()
{
    Date today, birthday(1, 29, 1927);
    const Date d2010(1, 1, 2010);
    cout << "\n Brigit's birthday: "
         << birthday.asString() << endl;
    today.setDate();
    cout << "\nToday's date: " << today.asString()
         << endl;
    ;
    if (today.isLess(d2010))
        cout << " Good luck for this decade \n"
             << endl;
    else
        cout << " See you next decade \n"
             << endl;
    Date holiday;
    int month, day, year;
    char c;
    cout << "\nWhen does your next vacation begin?\n"
         << "Enter in Month-Day-Year format: ";
    if (!(cin >> month >> c >> day >> c >> year))
        cerr << "Invalid input!\n"
             << endl;
    else if (!holiday.setDate(month, day, year))
        cerr << "Invalid date!\n"
             << endl;
    else
    {
        cout << "\nYour first vacation: ";
        holiday.print();
        if (today.getYear() < holiday.getYear())
            cout << "You should go on vacation this year!\n"
                 << endl;
        else
            cout << "Have a nice trip!\n"
                 << endl;
    }
    return 0;
}
