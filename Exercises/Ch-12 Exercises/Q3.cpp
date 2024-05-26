// Exercise 3
// a. The version of the function swap() opposite can be compiled without
// producing any error messages. However, the function will not swap the
// values of x and y when swap(&x,&y); is called.What is wrong?
//
// b. Test the correct pointer version of the function swap() found in this
// chapter.Then write and test a version of the function swap() that uses
// references instead of pointers.

// A version of swap() with incorrect logic.
// Find the error!

#include <iostream>

using namespace std;

void swap1(float &p1, float &p2)
{
    float temp; // Temporary variable

    temp = p1;
    p1 = p2;
    p2 = temp;
}

void swap(float *p1, float *p2)     // Pointer version
{
    float temp;                       // Temporary variable

    temp = *p1;                      // Above call points p1
    *p1  = *p2;                      // to x and p2 to y.
    *p2  = temp;
}

int main()
{
    float a = 10, b = 15;

    swap(&a, &b);

    cout << a << "\t" << b << endl;

    swap1(a, b);

    cout << a << "\t" << b << endl;

    return 0;
}