#include<iostream>
#include<iomanip>

using namespace std;
int main(){
    float a(0.123456), b(23.987), c(-123.456);

    cout << "Left-justify the number 0.123456 in an output field with a width of 15." << endl;
    cout<< setw(15) << left << a << endl;

    cout << "Output the number 23.987 as a fixed point number rounded to two decimal places, right-justifying the output in a field with a width of 12" << endl;
    cout << setw(12) << right << fixed << setprecision(2) << b << endl;
    
    cout << "Output the number –123.456 as an exponential and with four decimal spaces. How useful is a field width of 10?" << endl;
    cout << setw(10) << scientific << setprecision(4) << c << endl;
    cin >> a ;
    return 0;
}