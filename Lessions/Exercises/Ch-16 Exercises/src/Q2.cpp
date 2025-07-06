/**
 * @file Q2.cpp
 * @author Sumit Kumar (ravirajkarn21@gmail.com)
 * @details Chapter 14 introduced the sample class DayTime and the isLess() method.
 *          Define and initialize an array with four DayTime class objects.
 *          Then write a main function that first uses the print() method to display the
 *          four elements. Finally, find the largest and smallest elements and output them on
 *          screen.
 * @version 0.1
 * @date 2025-06-09
 * 
 * @copyright Copyright (c) 2025
 * 
**/

#include "280_DayTime.h"

int main() {
    DayTime times[] = {
        DayTime(10, 30, 45),
        DayTime(12, 15, 30),
        DayTime(8, 5, 20),
        DayTime(23, 59, 59)
    };

    // Print all elements
    for (auto& time : times) {
        time.print();
    }

    // Find the smallest and largest elements
    DayTime smallest = times[0];
    DayTime largest = times[0];

    for (const auto& time : times) {
        if (time.isLess(smallest)) {
            smallest = time;
        }
        if (!time.isLess(largest)) {
            largest = time;
        }
    }

    fmt::print(fg(fmt::color::yellow), "Smallest time: ");
    smallest.print();
    
    fmt::print(fg(fmt::color::yellow), "Largest time: ");
    largest.print();

    return 0;
}