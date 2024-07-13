/*
Exercise 2
a. Write an inline function, Max(double x, double y), which returns the 
maximum value of x and y. (Use Max instead of max to avoid a collision 
with other definitions of max.) Test the function by reading values from 
the keyboard.
Can the function Max() also be called using arguments of the types
char, int, or long?

b. Now overload Max() by adding a further inline function Max(char x,
char y) for arguments of type char .
Can the function Max() still be called with two arguments of type
int?
*/
#include <iostream>
#include <iomanip>

inline double Max(double x, double y){
    return ((x>=y)? x : y);   
}

inline char Max(char x, char y){
    return ((x>=y)? y : x);
}

int main(){
    double a, b;
    char aa, bb;

    std::cout << "Enter two number: ";
    std::cin >> a;
    std::cin >> b;
    std::cout << "your maximum number is:" << Max(a,b);

    std::cout << "\nEnter two character: ";
    std::cin >> aa;
    std::cin >> bb;
    std::cout << "your grates character is:" << Max(aa,bb);

    return 0;
}