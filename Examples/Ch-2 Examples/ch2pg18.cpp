#include <climits>
#include <iostream>
#include <cstdlib>

using namespace std;

int main ()
{
    cout << "Range of types int and usigned int" << endl << endl;
    cout << "Type             Minimum                Maximum"
         << endl
         << "------------------------------------------------------"
         <<endl;
    cout << "int           " << INT_MIN <<"              "<< INT_MAX << endl;
    cout << "unsigned int  " << "     0                   "<<UINT_MAX << endl;
    int a= 12.56;
    cin >> a ;
}