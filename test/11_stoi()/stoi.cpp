/*
~ check wether stoi convert negative number or not.
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int integer;
    string number = "-145";

    integer = stoi(number);

    integer = -45;

    cout << '\n' << integer << endl;

    return 0; 
}