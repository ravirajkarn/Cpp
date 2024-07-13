/*
Write a C++ program that reads any given character code (a positive integer)
from the keyboard and displays the corresponding character and the character
code as a decimal, an octal, and a hexadecimal on screen.

Why do you think the character P is output when the number 336 is entered?
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    unsigned char a;
    unsigned int b;
    cout << "enter number: ";
    cin >> b;

    a=b;

    cout << "character code: " << b << endl;
    cout << "character: " << a << endl;
    cout << "decimal number: " << dec << b << endl;
    cout << "hexadecimal number: " << hex << b << endl;
    cout << "octadecimal number: " << oct << b << endl;

    return 0;
}