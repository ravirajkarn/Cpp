// Ref2.cpp
// Demonstrating functions with parameters
// of reference type.
// --------------------------------------------------

#include <iostream>
#include <string>
using namespace std;
                        // Prototypes:
bool getClient( string& name, unsigned long& nr);
void putClient( const string& name, const unsigned long& nr);

int main()
{
    string clientName;
    unsigned long   clientNr;
    
    cout << "\nTo input and output client data \n"
         << endl;
    if( getClient( clientName, clientNr)) // Calls
        putClient( clientName, clientNr);
    else
        cout << "Invalid input!" << endl;
    
    return 0;
}

bool getClient( string& name, unsigned long& nr) // Definition
{
    cout << "\nTo input client data!\n"
        << " Name:   ";
    if( !getline( cin, name))  return false;
    
    cout << " Number: ";
    if( !( cin >> nr))  return false;
    
    return true;
}
                                         // Definition   
void putClient( const string& name, const unsigned long& nr)
{                      // name and nr can only be read!
    cout << "\n-------- Client Data ---------\n"
    << "\n Name:   ";  cout << name
    << "\n Number: ";  cout << nr << endl;
}