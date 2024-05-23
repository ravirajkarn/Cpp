// Reads integral decimal values and generates octal, decimal, and hexadecimal output.

#include <iostream>

using namespace std;

int main()
{
    int number;
    cout << "Please enter an integer: ";
    cin >> number;
    cout << uppercase       //forhex-degits
        << "octal \t decimal \t hexadecimal \n"
        << oct << number << "  \t"
        << dec << number << "\t\t"
        << hex << number << endl;
    return 0;   
} 
