// The function displayError() outputs an error message
// to a corresponding error number.
// --------------------------------------------------
#include <iostream>
using namespace std;
void displayError(int errorNr)
{
    static char* errorMsg[] = {
    "Invalid error number",
    "Error 1: Too much data ",
    "Error 2: Not enough memory ",
    "Error 3: No data available " };
    if (errorNr < 1 || errorNr > 3)
        errorNr = 0;
    cerr << errorMsg[errorNr] << endl;
}