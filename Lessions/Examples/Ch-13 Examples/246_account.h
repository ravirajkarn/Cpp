// account.h
// Defining the class Account.
// ---------------------------------------------------
#ifndef _ACCOUNT_       // Avoid multiple inclusions.
#define _ACCOUNT_

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Account
{
    private: // Sheltered members:
    string name;                // Account holder
    unsigned long nr;           // Account number
    double balance;             // Account balance
    public: //Public interface:
    bool init( const string&, unsigned long, double);
    void display();
};

// The method init() copies the given arguments
// into the private members of the class.
bool Account::init(const string& i_name,unsigned long i_nr,double i_balance)
{
    if( i_name.size() < 1)            // No empty name
    return false;
    name    = i_name;
    nr      = i_nr;
    balance = i_balance;
    return true;
}
// The method display() outputs private data.
void Account::display()
{
    cout << fixed << setprecision(2)
    << "--------------------------------------\n"
    << "Account holder:    " << name  << '\n'
    << "Account number:    " << nr    << '\n'
    << "Account balance:   " << balance << '\n'
    << "--------------------------------------\n"
    << endl;
}

#endif   //  _ACCOUNT_