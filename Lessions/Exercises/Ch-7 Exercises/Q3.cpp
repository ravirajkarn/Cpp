/*
Write a filter program to display the text contained in any given file.The
program should filter any control characters out of the input with the exception
of the characters \n (end-of-line) and \t (tabulator), which are to be treated as
normal characters for the purpose of this exercise. Control characters are
defined by codes 0 to 31.
    
    A sequence of control characters is to be represented by a single space
character.
    
    A single character, that is, a character appearing between two control
characters, is not to be output!
*/

// ---------------------------------------------------
//  NoCtrl.cpp
//  Filter to ignore control characters
//  To call e.g.:  NoCtrl < file
// ---------------------------------------------------
#include <iostream>
using namespace std;
#define isCtrl(c)    ( c >= 0  &&  c <= 31  \
&& c != '\n' && c != '\t')
int main()
{
char c, prec = 0;           // Character and predecessor
long nCtrl = 0, nChar = 0;  // Number of the following
// control characters or
// other characters
while( cin.get(c))
{
if( isCtrl(c))            // Control characters
{
++nCtrl;
nChar = 0;
}
else                      // Normal character
{
if( nCtrl > 0)
{
cout.put(' ');
nCtrl = 0;
}
switch( ++nChar)
{
case 1:   break;
case 2:   cout.put(prec);   // Predecessor and
default:  cout.put(c);      // current character
}
prec = c;
}
}
return 0;
}