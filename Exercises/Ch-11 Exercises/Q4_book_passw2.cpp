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

bool changePassword()    // Changes password.
{                        // Returns: true, if the
    // password has been changed
    string word1,word2;          // For input
    // To read a new password
    cout <<"\nEnter a new password (2 - 20 characters): ";
    cin.sync();                   // Discards former input
    cin >> setw(20) >> word1;
    if( word1.size() > 1)
    {
        cout << "\nEnter the password once more: ";
        cin >> setw(20) >> word2;
        if( word1 == word2)       // Password confirmed?
        {                         // Yes!
            secret = word1;
            return true;
        }
    }      
    
    return false;                // No new password
}