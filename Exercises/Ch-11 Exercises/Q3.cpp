// Exercise 3
//
// Test your knowledge of external and static variables by reference to the
// program on the opposite page. What screen output does the program generate?

// static.cpp
// Tests an internal static variable
// ---------------------------------------------------
#include <iostream>
#include <iomanip>

using namespace std;

double x = 0.5, fun(void);

int main()
{
    while( x < 10.0 )
    {
        x += fun();
        cout << "     Within main(): " << setw(5) << x << endl;
    }
    return 0;
}

double fun()
{
    static double x = 0;
    cout << "      Within fun():" << setw(5) << x++;
    
    return x;
}

/*
* Answer: Trial1
    Within fun(): 1      Within main(): 1.5
    Within fun(): 2      Within main(): 2.5
    Within fun(): 3      Within main(): 3.5
    Within fun(): 4      Within main(): 4.5
    Within fun(): 5      Within main(): 5.5
    Within fun(): 6      Within main(): 6.5
    Within fun(): 7      Within main(): 7.5
    Within fun(): 8      Within main(): 8.5
    Within fun(): 9      Within main(): 9.5
    Within fun(): 10     Within main(): 10.5
*/