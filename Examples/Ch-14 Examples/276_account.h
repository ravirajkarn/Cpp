// account.h
// Account class with read-only methods.
// ----------------------------------------------------
#ifndef _ACCOUNT_
#define _ACCOUNT_
#include <iostream>
#include <iomanip>
#include <string>
#include"274_account.h"
using namespace std;
class Account
{
private:
    string name;      // Account holder
    unsigned long nr; // Account number
    double state; 

     // Sheltered members
    // Data members:  as before
public: // Public interface
    // Constructors and destructor
    // as before
    // constructors, destructor:
    Account(const string &a_name = "X",
            unsigned long a_nr = 1111111L,
            double a_state = 0.0)
    {
        name = a_name;
        nr = a_nr;
        state = a_state;
    }
    ~Account() {}

    // Get-methods:
    const string &
    getName() const
    {
        return name;
    }
    unsigned long getNr() const { return nr; }
    double getState() const { return state; }
    // Set-methods:
    // as before
        // Additional methods:
        void
        display() const;
};
// display() outputs the data of class Account.
inline void Account::display() const
{
    cout << fixed << setprecision(2)
         << "--------------------------------------\n"
         << "Account holder:   " << name << '\n'
         << "Account number:   " << nr << '\n'
         << "Account state:    " << state << '\n'
         << "--------------------------------------\n"
         << endl;
}
#endif //  _ACCOUNT_