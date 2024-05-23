// ■    Define an inline function called calculate() that returns the sum of two
// numbers for the header file tool1.h.The function interface is as follows:
// double calculate(double num1, double num2); 

#ifndef _TOOL1_H_
#define _TOOL1_H_

inline double calculate(double num1, double num2){
    return (num1 + num2);
}

#endif  // end of Tool1.h 