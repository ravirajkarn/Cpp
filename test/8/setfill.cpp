/*
~ To check nature of setw() function.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    string test("hello");

    cout << setw(7) << setfill('1') <<  test << endl;
    return 0;
}