// Exercise 2
//
// You are developing a large-scale program and intend to use two commercial
// libraries, tool1 and tool2.The names of types, functions, macros, and so on are
// declared in the header files tool1.h and tool2.h for users of these libraries.
// Unfortunately, the libraries use the same global names in part. In order to use
// both libraries, you will need to define namespaces.
// Write the following program to simulate this situation:
// ■    Define an inline function called calculate() that returns the sum of two
// numbers for the header file tool1.h.The function interface is as follows:
// double calculate(double num1, double num2); 
// ■    Define an inline function called calculate() that returns the product of
// two numbers for a second header file tool2.h.This function has the
// same interface as the function in tool1.h.
// ■    Then write a source file containing a main function that calls both functions 
// with test values and outputs the results.
// resolve potential naming conflicts, define the namespaces TOOL1 and
// TOOL2 that include the relevant header files.

#include <iostream>
#include <iomanip>

namespace tool1{
    #include "tool1.h"
}

namespace tool2
{
    #include "tool2.h"
} // namespace tool2.h

using namespace std;

int main(){
    double a, b;
    
    cout << "Enter two number to calculate." << endl;
    cin >> a;
    cin >> b;
    cin.sync();

    cout << "product of the two number is: " << tool2::calculate(a,b) << "\nSum of the two number is: "<< tool1::calculate(a,b) << endl;

    return 0;
}