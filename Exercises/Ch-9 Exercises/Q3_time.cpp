/*

Write down the screen output for the program on the opposite page.

*/

/*
✓NOTE

The  function  time() returns  the  current  time  as  the  number  of  seconds  since  1/1/1970,  0:0.  The
number  of  seconds  is  stored  in  the  variable  sec,  whose  address  was  supplied  as  &sec when  the
function was called.
    The function ctime() converts the number of seconds to a string with a date and time and returns
this string. The string comprises exactly 26 characters including the null character \0 and has the
following format:
    Weekday Month Day Hr:Min:Sec Year\n\0

    Example:        Wed Jan 05 02:03:55 2000\n\0

*/

// timeStr.cpp
// Demonstrates operations on a string containing
// the present time.

#include <iostream>
#include <string>
#include <ctime>         // For time(), ctime(), ...

using namespace std;

int main()
{
    long sec;
    time( &sec);            // Reads the present time
                            // (in seconds) into sec.
    string tm = ctime( &sec);     // Converts the
                                  // seconds to a string.
    
    cout << "Date and time: " << tm << endl;
    
    string hr(tm, 11, 2);  // Substring of tm starting at
                           // position 11, 2 characters long.
    string greeting("Have a wonderful ");

    if( hr < "10")             // Compares strings
        greeting += "Morning!";
    else if( hr < "17")
        greeting += "Day!";
    else
        greeting += "Evening!";

    cout << greeting << endl;

    return 0;
}