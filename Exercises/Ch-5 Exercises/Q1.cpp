/*

What values do the following arithmetic expressions have?

a. 3/10         b. 11%4         c. 15/2.0
d. 3 + 4 % 5    e. 3 * 7 % 4    f. 7 % 4 * 3

*/

#include <iostream>

using namespace std;

int main(){
    
    cout << "A. 3/10 =  "      << 3/10 << endl;
    cout << "B. 11%4 =  "      << 11%4 << endl;
    cout << "C. 15/2.0 =  "    << 15/2.0 << endl;
    cout << "D. 3 + 4 % 5 =  " << 3+4%5 << endl;
    cout << "E. 3 * 7 % 4 =  " << 3 * 7 % 4 << endl;
    cout << "F. 7 % 4 * 3 =  " << 7 % 4 * 3 << endl;
    
    return 0;

}