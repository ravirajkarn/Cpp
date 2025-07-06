// account.h
// Defining class Account with two constructors.
// ---------------------------------------------------
#ifndef _ACCOUNT_
#define _ACCOUNT_

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Account
{
private:              // Sheltered members:
    string name;      // Account holder
    unsigned long nr; // Account number
    double state;     // State of the account
public:               // Public interface:
    Account(const string &, unsigned long, double);
    Account(string &);
    bool init(const string &, unsigned long, double);
    void display();
};

Account::Account(const string &a_name = "X",
                 unsigned long a_nr = 1111 , double a_state = 0.0)
{
    nr = a_nr;
    name = a_name;
    state = a_state;
}

Account::Account(string &a_name)
{
    name = a_name;
    nr = 1111111;
    state = 0.0;
}

// 272_account.h
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

// Account::Account(const string &a_name = "X",
//             unsigned long a_nr = 1111111L,
//             double a_state = 0.0)
//     {
//         name = a_name;
//         nr = a_nr;
//         state = a_state;
//     }
// Account::~Account() {} // Dummy destructor: implicit inline
// 272_account.h end.
#endif //  _ACCOUNT_