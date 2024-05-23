//! Exercise 2
//
// Write a void type function called circle()to calculate the circumference and
// area of a circle.The radius and two variables are passed to the function, which
// therefore has three parameters:
//
// Parameters: A read-only reference to double for the radius and two
//             references to double that the function uses to store the area
//             and circumference of the circle.
/*****************s***********************************************************/
/* ✓NOTE                                                                   **/
/*      Given a circle with radius r:                                       **/
/* Area = π * r * r and circumference = 2 * π * r where π = 3.1415926536    **/
/*****************************************************************************/
// Test the function circle() by outputting a table containing the radius, the
// circumference, and the area for the radii 0.5, 1.0, 1.5, . . . , 10.0.

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const long double &pi = 3.1415926536 ; 

void circle(double &radius, double &area, double &circumference)
{
    area = pi * radius * radius;
    circumference = 2 * pi * radius;
}

int main()
{
    double radius = 3 , area, circumference;
    
    cout << "           radius:          *       circumference:       *             area:          \n" << setw(86) << setfill('*') << "*\n" << setfill(' ') ;
    
    circle (radius, area, circumference);
    cout << to_string(radius).length() << setw(((to_string(radius).length()/2)+14)) << radius << setw(14-(to_string(radius).length()/2))<< "*" << setw(((to_string(circumference).length()/2)+14)) << circumference << setw(14-(to_string(circumference).length()/2))<< "*" << setw(((to_string(area).length()/2)+14)) << area << setw(14-(to_string(area).length()/2))<< "*\n" ;
    
    return 0;
}