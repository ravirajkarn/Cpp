// To display hexadecimal integer literals and
// decimal integer literals.
//
#include <iostream>
using namespace std;
int main()
{                                                       
cout << "Value of 0xFF = " << 0xFF << " decimal"  // cout outputs integers as decimal integers:
<< endl; // Output: 255 decimal
// The manipulator hex changes output to hexadecimal
// format (dec changes to decimal format):
cout << "Value of 27 = " << hex << 27 <<" hexadecimal"
<< endl; // Output: 1b hexadecimal
return 0;
}