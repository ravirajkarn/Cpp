// account.h
// Class Account with set- and get-methods.
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
    // Access methods:
    const string &getName() { return name; }
    bool setName(const string &s)
    {
        if (s.size() < 1) // No empty name
            return false;
        name = s;
        return true;
    }
    unsigned long getNr() { return nr; }
    void setNr(unsigned long n) { nr = n; }
    double getState() { return state; }
    void setState(double x) { state = x; }
    void display();
};
// inline definition of display() as before.
#endif //  _ACCOUNT_