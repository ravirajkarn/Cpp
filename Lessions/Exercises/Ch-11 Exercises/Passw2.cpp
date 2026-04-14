// Passw1.cpp
// The functions getPassword() and timediff()
// to read and examine a password.
// -----------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

long timediff(void);                      // Prototype
static string secret = "ISUS"; // Password
static long  maxcount = 3, maxtime = 60; // Limits

bool getPassword()     // Enters and checks a password.
{              // Return value: true, if password is ok.
    bool ok_flag = false;       // For return value
    string word;                // For input
    int count = 0, time = 0;
    timediff();                 // To start the stop watch

    while( ok_flag != true && ++count <= maxcount)   // Number of attempts
    {
        cout << "\n\nInput the password:  ";
        cin.sync();                // Clear input buffer
        cin >> setw(20) >> word;
        time += timediff();

        if( time >= maxtime )      // Within time limit?
        break;                  // No!
        if( word != secret)
        cout << "Invalid password!" << endl;
        else
        ok_flag = true;       // Give permission
    }   

    return ok_flag;            // Result
}

long timediff()          // Returns the number of
{                        // seconds after the last call.
    static long  sec = 0; // Time of last call.
    long  oldsec = sec;      // Saves previous time.
    time( &sec);             // Reads new time.
    return (sec - oldsec);   // Returns the difference.
}

void changePassword(void){
    string a, b;
    cin.sync();
    cout << "\n\t Enter new Password: ";
    getline(cin, a);
    cout << "\n\t Re-Enter the Password: ";
    getline(cin, b);
    if(a.length() > 1)
    if (a == b)
        secret = a;
    else
        cout << "Password not Matched";
}