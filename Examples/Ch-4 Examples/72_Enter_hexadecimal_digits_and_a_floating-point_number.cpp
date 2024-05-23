#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int number = 0;
    cout << "\nEnter a hexadecimal number:"<< endl;
    cin >> hex >> number; //input hex-number 
    cout <<"Your decimal input: " << number << endl;
    // if an invalid imput occurred:
    cin.sync();
    cin.clear();
    double x1 = 0.0, x2 =0.0;
    cout << "\n Now enter two floating-Point values: "<<endl;
    cout << "1. number: ";
    cin >> x1 ;
    cout <<"2. number: ";
    cin>> x2;
    cout << fixed << setprecision (2) << "\nThe sum of both number: " << setw(10) << x1 +x2 << endl;
    cout << fixed << setprecision (2) << "\nThe Product of both number: " << setw(10) << x1 * x2 << endl;
    return 0;
}