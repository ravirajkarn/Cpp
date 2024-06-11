/*
Exercise
A program needs a class to represent the date.
    ■ Define the class Date for this purpose using three integral data members
for day, month, and year.Additionally, declare the following methods:
void init( int month, int day, int year);
void init(void);
void print(void);
Store the definition of the class Date in a header file.
    ■ Implement the methods for the class Date in a separate source file:
1. The  method  print() outputs  the  date  to  standard  output  using  the
format Month-Day-Year.
2. The  method  init() uses  three  parameters  and  copies  the  values
passed to it to corresponding members. A range check is not required
at this stage, but will be added later.
3. The method init() without parameters writes the current date to the
corresponding members.

The structure tm and sample calls to this function are included opposite.
The type time_t is defined as long in ctime.
The function time() returns the system time expressed as a num-
ber of seconds and writes this value to the variable referenced by ptr-
Sec. This  value  can  be  passed  to  the  function  localtime() that
converts the number of seconds to the local type tm date and returns
a pointer to this structure.
    ■ Test the class Date using an application program that once more is stored
in a separate source file.To this end, define two objects for the class and
display the current date. Use object assignments and—as an additional
exercise—references and pointers to objects.
*/

#include <iostream>
#include <ctime>
#include "timee.h"

using namespace std;

// 1. The  method  print() outputs  the  date  to  standard  output  using  the format Month-Day-Year.
void timee::print(){
    cout << "\n Today is: " << Months  << " " << Day << " " << Year << '\n';
}

//     2. The  method  init() uses  three  parameters  and  copies  the  values
// passed to it to corresponding members. A range check is not required
// at this stage, but will be added later.
void timee::init(int months, int day, int year){

    Day = day;
    Months = months;
    Year = year;

}

// 3. The method init() without parameters writes the current date to the corresponding members.
void timee::init(void){
    // initializing variable 
    time_t sec;

    // Giving no of time to the sec.
    time(&sec);

    Months = localtime(&sec)->tm_mon + 1;
    Day = (*localtime(&sec)).tm_mday;
    Year = localtime(&sec) -> tm_year + 1900; 
}

int main()
{
    timee sumit;

    sumit.init();

    sumit.print();

    return 0;
}
