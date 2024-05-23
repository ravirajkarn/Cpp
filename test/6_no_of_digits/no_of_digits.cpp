/*
* ****************************************************************
!               Number of digits in a number
* ****************************************************************

~   This project will demonstrate all possible was to find number
~   of digits in a number.
~
? Eg.- 45786  has 5 digits.
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int mth1(int n){   //! Second best method  // limitations: it Dose not work on value <=0.
    return (trunc(log10(n)) + 1) ;
}

int mth2(int n){      //! Best method.
    return (std::to_string(n).length());  //? to_string() ~~~ convert the number into string.
}

int main(){
    int a; 
    cout << "Enter a number: " ; cin >> a;
    
    cout << mth1(a) << endl;
    cout << mth2(a) << endl;
    
    return 0;
}