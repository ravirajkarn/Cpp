// toupper.cpp: Afilter that converts to capitals.
// ---------------------------------------------------------

#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    char c;

    long nChar = 0,  // counts all characters 
         nconv = 0;  // and converted characters 
    
    while (cin.get(c))
    {
        ++nChar;
        if (islower(c))
        {
            c=toupper(c);
            ++nconv;
        }
        cout.put(c);
    }
    clog << "\ntotal of characters:     " << nChar 
         << "\nTotal fo converted characters: " << nconv
         << endl;
    
    return 0;    
}