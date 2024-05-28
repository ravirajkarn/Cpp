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
#include <cmath>
#include <string>

using namespace std;

const long double &pi = 3.1415926536;

void circle(double &radius, double &area, double &circumference)
{
    area = pi * radius * radius;
    circumference = 2 * pi * radius;
}

int length(const double &num, int precision = 1) // imp v2.0
{
    string conv = to_string(num);

    // Removing trailing zero
    conv.erase(conv.find_last_not_of('0') + precision, string::npos);

    // Removal of decimal point if it's last character.
    if (conv.back() == '.')
        conv.pop_back();

    return conv.length();
}

int main()
{
    cout << "\n           radius:          *       circumference:       *             area:          \n"
         << setw(87) << setfill('*') << "*\n"
         << setfill(' ');

    for (double radius(5.5), area, circumference; radius < 10.0; radius = radius + 0.5)
    {
        circle(radius, area, circumference);
        int temp_rad = length(radius), temp_area = length(area),
            temp_circum = length(circumference);

        cout << setw(((temp_rad / 2) + 14)) << radius
             << setw(15 - (temp_rad / 2)) << "*"
             << setw(((temp_circum / 2) + 14)) << circumference
             << setw(15 - (temp_circum / 2)) << "*"
             << setw(((temp_area / 2) + 14)) << area
             << setw(15 - (temp_area / 2)) << "*\n";
    }

    return 0;
}

/*
~ The program is running fine problem is in alignment of number. execute the program and see. 
~ problem is face on value of radius = 6; 7.5; 8.5; 9; 9.5; 10.

? any suggestion comment down. I Will definitely find solution in future.
*/
