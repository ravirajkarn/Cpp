// Exercise 4
//
// a. The function getPassword(), which checks password input, was introduced
// previously as an example of the use of static variables. Modify the
// source file Passw1.cpp, which contains the function getPassword(), by
// adding the function changePassword().This function allows the user to
// change his or her password. Save the modified source file as
// Passw2.cpp.
//
// b. A large-scale program with several users is used to perform bookings.
// Only authorized users, that is, users that have access to the password, are
// allowed to perform bookings.
// In the initial stages of program development, you need to test the
// functionality of the source file, Passw2.cpp.To do so, create a new
// source file with a main function that contains only the following menu
// items in its main loop:
// B = Booking
// E = End of program
// When B is typed, the password is first checked. If the user enters the
// correct password, he or she can change the password.The program does
// not need to perform any real bookings

#include <iostream>
#include <iomanip>
#include <windows.h>
#include "Passw2.cpp"

void Clear(void)
{
    COORD topLeft = {0, 0};
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    FillConsoleOutputAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE, screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    SetConsoleCursorPosition(console, topLeft);
}

using namespace std;

int main()
{
    char check;
    bool correctpassw;
    cout << "\tWhat do you want to do?"
         << "\nB = Booking"
         << "\nE = End of Program." << endl;
    cin.get(check);
    Clear();
    
    if(check == 'B' ||'b'){
        correctpassw = getPassword();
        Clear();
        if (correctpassw == true)
        {
            Clear();
            cout<< "Do you want to change the password? ";
            cin >> check;
            if(check == 'Y' || 'y'){
                changePassword();
            }
        }
    }
    return 0;
}