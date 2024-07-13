// -----------------------------------------------------
// Password.cpp
// Testing the functions getPassword() and
// changePassword().
//
// After entering the password correctly (max. three
// attempts within 60 seconds), the user can change it.
// -----------------------------------------------------
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <windows.h>
#include "Q4_book_passw2.cpp"

using namespace std;

bool getPassword(void);            // Read a password.
bool changePassword(void);         // Change a password.

// Inline functions:
inline void cls()  
{ 
    COORD topLeft = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    FillConsoleOutputAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE, screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    SetConsoleCursorPosition(console, topLeft);
}

inline void go_on()
{
    cout << "\n\nGo on with return! ";
    cin.sync();  cin.clear();          // Only new input
    while( cin.get() != '\n')
    ;
}

inline char getYesOrNo()   // Read character Y or N.
{
    char c = 0;
    cin.sync();  cin.clear();          // Just new input
    do
    {
        cin.get(c);
        c = toupper(c); // Permitting lower case letters also.
    }
    
    while( c != 'Y'  && c != 'N');
    
    return c;
}

static string header = "\n\n      ****  Test password handling  ****\n\n";

static string menu =
"\n\n              B = Booking "
"\n\n              E = End of program"
"\n\n Your choice:   ";

int main()
{
    char choice = 0;
    
    while( choice != 'E')
    {
        cls();   cout << header << menu;  // Header and Menu
        cin.get(choice);   choice = toupper(choice);
        cls();   cout << header << endl;  // Header
        switch( choice)
        {
            case 'B':                       // Booking
                if( !getPassword() )
                {
                    cout << "Access denied!" << endl;
                    go_on();
                }
                else
                { 
                    cout << "Welcome!\n\n"
                    << "Do you want to change the password? (y/n)";
                    if( getYesOrNo() == 'Y')
                    {          
                        if( changePassword() )
                        cout << "Password changed!" << endl;
                        else
                        cout << "Password unchanged!" << endl;
                        go_on();
                    }
                    // Place statements for booking here.
                }
                break;
            case 'E':
                cls();  cout << "\n    Bye Bye!" << endl;
                break;
        }
    } // End of while
    
    return 0;
}