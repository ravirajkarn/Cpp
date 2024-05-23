#ifndef _Q1_H_
#define _Q1_H__


#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

// The macro ABS, which returns the absolue value of a number,

#ifndef ABS
#define ABS( input ) (input = ((input < 0) ? (-(input)) : (input)))
#endif

#ifndef MAX
#define MAX(a,b) ((a>b) ? a : b)
#endif

#endif // End of Q1.h