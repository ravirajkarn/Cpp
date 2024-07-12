// result3_t.cpp
// Uses the new class Result.
// ---------------------------------------------------
#include "304_result3.h"
#include "304_result3.cpp"
#include <iostream>

using namespace std;

int main() // Some air temperature measurements
{
    DayTime morning(6, 45);
    Result temp1(6.45, morning),
        temp2(11.2, 12, 0, 0);
    double temp = 0.0;
    cout << "\nWhat is the air temperature now? ";
    cin >> temp;
    Result temp3(temp); // At current time.
    cout << "\n Temperature   Time  \n"
         << "-------------------------" << endl;
    temp1.print();
    temp2.print();
    temp3.print();
    cout
        << "\n Minimum Temperature: " << Result::getMin()
        << "\n Maximum Temperature: " << Result::getMax()
        << endl;
    return 0;
}