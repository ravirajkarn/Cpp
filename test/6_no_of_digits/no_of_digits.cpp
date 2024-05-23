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

/*
! Why you need this?
! last version flows: It dose not work properly with double type. It always return 8 digits.
? Improve version is as follows: 
*/
int mth2_imp(double &num, int precision = 1){ // imp v2.0

    string conv = to_string(num);

    // Removing trailing zero
    conv.erase(conv.find_last_not_of('0') + precision, string::npos) ;  

    //Removal of decimal point if it's last character.
    if (conv.back()== '.')
    {
        conv.pop_back();
    }

    return conv.length();
}

int main(){
    double a; 
    cout << "Enter a number: " ; cin >> a;
    
    cout << mth1(a) << endl;
    cout << mth2(a) << endl;
    cout << mth2_imp(a) << "\t" << a << endl ;
    
    return 0;
}