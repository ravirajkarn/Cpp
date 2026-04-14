/*
    Rewrite the EuroDoll.cpp program in this chapter to replace both the for loops with while loops.

*/
/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~EuroDoll.cpp~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// EuroDoll.cpp
// Outputs a table of exchange:  Euro and US-$

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    long   euro, maxEuro;     // Amount in Euros
    double rate;              // Exchange rate Euro <-> $

    cout << "\n* * * TABLE OF EXCHANGE " <<  " Euro - US-$ * * *\n\n";
    cout << "\nPlease give the rate of exchange: "" one Euro in US-$: ";
    cin >> rate;
    cout << "\nPlease enter the maximum euro: ";
    cin >> maxEuro; //  --- Outputs the table  --- // Titles of columns:

    cout << '\n' << setw(12) << "Euro" << setw(20) << "US-$" << "\t\tRate: " << rate << endl; // Formatting US-$:
    cout << fixed << setprecision(2) << endl;

    long lower, upper,         // Lower and upper limit
    step;                 // Step width // The outer loop determines the actual // lower limit and the step width:

    for( lower=1, step=1; lower <= maxEuro; step*= 10, lower = 2*step)  // The inner loop outputs a "block":
    for( euro = lower, upper = step*10; euro <= upper && euro <= maxEuro; euro+=step)
    cout << setw(12) << euro << setw(20) << euro*rate << endl;
    
    return 0;
}
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    long euro, maxEuro;
    double rate;

    cout << "\n* * * Table of EXCHANGE Euro -US-$ * * *\n\n\nPlease give the rate of exchange: One Euro in US-$: ";
    cin >> rate;
    cout << "\nPlease enter the maximum euro: ";
    cin >> maxEuro;

    cout << endl << setw(12) << "Euro" << setw(20) << "US-$" << "\t\tRate: " << rate << endl;
    cout << fixed << setprecision(2) << endl;

    int step(1);

    while(step<=maxEuro){
        cout << setw(12) << step << setw(20) << step*rate << endl;
        step++;
    }

    return 0;
} 