// account.cpp
// Defines methods init() and display().
// ---------------------------------------------------
#include "246_account.h" // Class definition
#include <iostream>
#include <iomanip>

using namespace std;

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