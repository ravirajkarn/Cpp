#include <iostream>

using namespace std;
int main()
{
    int i(2), j(8);
    cout << i++ << endl;       // Output:  2
    cout << i   << endl;       // Output:  3
    cout << j-- << endl;       // Output:  8
    cout << --j << endl;       // Output:  6
    return 0;
}