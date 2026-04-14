#ifndef _POSITION_H_
#define _POSITION_H_ 

#include <iostream>
#include <iomanip>
//#include <windows.h>

using namespace std;

int n (0);

#ifndef LOCATION
#define LOCATION(y,x,object)   for(int a = 1 ; a <= y-1 ; a++){cout <<"\n";} n = (2 * x) ; cout << setw(n) << setfill(' ') << " " << object;
#endif //* end of LOCATION


#endif //* end of _POSITION_H_