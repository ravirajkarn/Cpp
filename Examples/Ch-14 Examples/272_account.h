// account.h
// New definition of class Account with inline methods
// ----------------------------------------------------
#ifndef _ACCOUNT_
#define _ACCOUNT_
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
class Account
{
private:              // Sheltered members:
    string name;      // Account holder
    unsigned long nr; // Account number
    double state;     // State of the account
public:               // Public interface:
    // Constructors: implicit inline
    Account(const string &a_name = "X",
            unsigned long a_nr = 1111111L,
            double a_state = 0.0)
    {
        name = a_name;
        nr = a_nr;
        state = a_state;
    }
    ~Account() {} // Dummy destructor: implicit inline
    void display();
};
// display() outputs data of class Account.
inline void Account::display() // Explicit inline
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