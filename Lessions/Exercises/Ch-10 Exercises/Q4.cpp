/*
Exercise 4
Write a function pow(double base, int exp) to calculate integral powers of
floating-point numbers.
Arguments: The base of type double and the exponent of type int.
Returns: The power base exp of type double.
For example, calling pow(2.5, 3) returns the value
2.53 =  2.5 * 2.5 * 2.5  =  15.625
This definition of the function pow()means overloading the standard function
pow(), which is called with two double values.
Test your function by reading one value each for the base and the exponent
from the keyboard. Compare the result of your function with the result of the
standard function.
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double pow(double base = 1, int power = 1){
    double result(1) ;
    if (base == 0)
    {
        return 0 ;
    }
    
    for (int i = 0; i < power; i++)
    result = base * result;
    
    return result;
}

int main(){
    double b, ee;
    int e;
    ee = e;
    cout << "Enter base and power to solve: " ; cin >> b; cin >> e;

    cout << b << " to the power of " << e << " is equal to: " << pow(b,e) << "\t" << pow(b,ee);
    return 0;
}