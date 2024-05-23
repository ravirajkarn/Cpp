// Cutline1.cpp
// A filter to remove white-space characters
// at the ends of lines.
// --------------------------------------------------
#include <iostream>
#include <string>
#include "200_cutline2.cpp"

using namespace std;

void cutline( void );         // Prototype
string line;                  // Global string

int main()
{
    while( getline(cin, line)) // As long as a line
    {                          // can be read.
    cutline();               // Shorten the line.
    cout << line << endl;    // Output the line.
    }
    
    return 0;
}