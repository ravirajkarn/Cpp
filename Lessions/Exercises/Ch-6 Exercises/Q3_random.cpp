/*

    Write a C++ program that reads an integer between 0 and 65535 from the keyboard and uses it to seed a random number generator.Then output 20 random numbers between 1 and 100 on screen.

*/

// random.cpp
// Outputs 20 random numbers from 1 to 100.

#include <iostream>
#include <time.h>
#include <stdlib.h>   // Prototypes of srand() and rand()
#include <iomanip>

using namespace std;

int main()
{
    unsigned int  i, seed;
    cout << "\nPlease type an integer between " "0 and 65535: ";
    
    cin >> seed;     // Reads an integer.
    srand( seed);    // Seeds the random
                     // number generator.
    
    cout << "\n\n            " "******   RANDOM NUMBERS   ******\n\n";
    
    for( i = 1 ; i <= 20 ; ++i)
    {
        cout << setw(20) << i << ". random number = " << setw(3) <<(rand() % 100 + 1) << endl;
    }
    
    return 0;
}