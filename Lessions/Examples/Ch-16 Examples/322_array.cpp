// array.cpp
// To input numbers into an array and output after.
// ----------------------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const int MAXCNT = 10;      // Constant 
    float arr[MAXCNT], x;       // Array, temp. variable
    int i, cnt;                 // Index, Quantity

    cout << "Enter up to 10 numbers \n"
         << "(Quit with a letter) :" << endl;
    for(i = 0; i < MAXCNT && cin >> x; ++i) {
        arr[i] = x;
    }
    cnt = i;
    cout << "The given numbers:\n" << endl;
    for(i=0; i < cnt; ++i) {
        cout << setw(10) << arr[i];
    }
    cout << endl;
    return 0;
}