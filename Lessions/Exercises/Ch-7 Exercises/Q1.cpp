/*
Please write
    a. the macro ABS, which returns the absolute value of a number,
    b. the macro MAX, which determines the greater of two numbers.
In both cases use the conditional operator ?: .
    Add these macros and other macros from this chapter to the header file
myMacros.h and then test the macros.
    If your system supports screen control macros, also add some screen control
macros to the header. For example, you could write a macro named
COLOR(f,b) to define the foreground and background colors for the following
output.
--------------------------------------------------------------------------------------
*/
#include <iostream>
#include <iomanip>
#include "Q1.h"

using namespace std;

int main()
{
    int a, b;

    while (cin >> a )
    {
        a = ABS(a);
        cout << a << endl;
        cin >> b;
        cout << "max" << MAX(a,b) << endl;
    }

    return 0;

}