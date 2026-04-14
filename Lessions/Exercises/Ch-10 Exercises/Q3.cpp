/*
Exercise 3
The factorial n! of a positive integer n is defined as
n! = 1*2*3 . . . * (n-1) * n
Where 0! = 1
Write a function to calculate the factorial of a number.
Argument: A number n of type unsigned int.
Returns: The factorial n! of type long double.
Formulate two versions of the function, where the factorial is
a. calculated using a loop
b. calculated recursively
Test both functions by outputting the factorials of the numbers 0 to 20 as shown
opposite on screen.
*/

#include <iostream>
#include <iomanip>

using namespace std;

long double factorial_loop(unsigned int n){
    long double factor(1);
    
    if(n!=0)
    for (int i = 1; i <= n; i++)
    factor = factor * i;

    return factor;    
}

long double factorial_recursively(unsigned int n){
    long double factor(1);
    if (n>1)
    factor=factorial_recursively(n-1);
    
    return (n*factor);
}

int main(){
    unsigned int a ;
    cout << "enter number to find factor: ";
    cin >> a;

    cout << "Factor of " << a << "! with loop function = " << factorial_loop(a) << endl;
    cout << "Factor of " << a << "! with recursive function = " << factorial_recursively(a) << endl;

    cout << setw(50) << setfill('-') << "-" << endl << setfill(' ');
    cout << "\n\n\n" << setw(10) << "n" << setw(std::to_string(factorial_loop(20)).length()) << "factorial of n";
    cout <<endl << setw(50) << setfill('-') << "-" << endl << setfill(' ');
    for (int i = 0; i <= 20; i++)
    {
        cout << setw(10) << i << setw(std::to_string(factorial_loop(20)).length()+5) << setprecision(std::to_string(factorial_loop(20)).length()) << factorial_loop(i) << endl;
    }
    
    return 0; 
}