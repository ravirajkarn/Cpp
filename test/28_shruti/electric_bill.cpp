#include <iostream>
using namespace std;

int bill(int units){
    int total = 0;
    if (units <= 100)
    {
        total = units * 2;
    }
    else if (units <= 200)
    {
        total = 200 + (units - 100) * 3;
    }
    else
    {
        total = 500 + (units - 200) * 4;
    }

    return total = total + 50;
}

int main(){
    int units;
    cout << "Enter the number of units: ";
    cin >> units;
    cout << "The total bill is: " << bill(units) << endl;
    return 0;
}