/*

The int variable x contains the number 7. Calculate the value of the following
logical expressions:
    
    a. x < 10 && x >= –1
    b. !x && x >= 3
    c. x++ == 8 || x == 7

*/

#include <iostream>

using namespace std;

int main(){
    int x = 7;
    bool check(0);
    
    check = x < 10 && x>= -1;
    cout << check << endl;

    check = !x && x >= 3;
    cout << check << endl;

    check = x++ ==8 || x==7;
    cout << check << endl;
    
    return 0;
}