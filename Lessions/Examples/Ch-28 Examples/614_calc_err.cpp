// calc_err.cpp: Tests the function calc()
//               which throws exceptions.
#include<iostream>
#include<string>

// cspell:ignore namespace, cspell, cerr, cal, bool,
using namespace std;

class Error
{
    // Infos about the error
};

double calc(int a, int b);

int main() {
    int x, y;
    double res;
    bool flag = false;
    do {
        try
        {
            cout << "Enter tow positive integers: ";
            cin >> x >> y;
            res = calc(x, y);
            cout << x << "/" << y << " = " << res << endl;
            flag = true;
        }
        catch(string& s)
        {
            cerr << s << endl;
        }
        catch( Error& )
        {
            cerr << "Division by 0! " << endl;
        }
        catch(...)
        {
            cout << "Unknown error occurred." << endl;
            exit(1);
        }
        
    }while ( !flag );    
}

double calc(int a, int b) {
    if (b == 0) {
        throw Error(); // Custom error for division by zero
    }
    if( b < 0 || a < 0 ) {
        throw string("Both numbers must be positive integers.");
    }
    // Perform the division and return the result
    return static_cast<double>(a) / b;
}