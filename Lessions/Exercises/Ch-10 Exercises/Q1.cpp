/*
!Exercise 1

a. Write the function sum() with four parameters that calculates the arguments provided and returns their sum.
    Parameters: Four variables of type long.
    Returns: The sum of type long.

Use the default argument 0 to declare the last two parameter of the
function sum().Test the function sum() by calling it by all three possible
methods. Use random integers as arguments.

b. Now restructure your program to store the functions main() and
sum() in individual source files, for example, sum_t.cpp and sum.cpp .

*/

#include <iostream>
#include <iomanip>
#include <time.h>
#include <cstdlib>
#include "sum_t.cpp"

int main(){
    srand((unsigned int)time(NULL)); //initializations of random number.
    long a(rand()), b(rand()), c(rand());
    std::cout << a << "\t" << b << "\t" << c << std::endl << sum(a) << "\t" << sum(a,b)<< "\t" << sum(a,b,c) << std::endl;
    return 0;    
}
