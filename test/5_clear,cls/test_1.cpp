//! This program will test, How to clear the output or clean the screen


#include <iostream>
#include <iomanip>
#include <windows.h>       //?  clearconsole()
#include <cstdlib>         //?  system();

using namespace std;

// #define CLS (cout<< "\033[2J")      //Clear screen  //! Taken from ball1.cpp // Not working // used in linux

void clearConsole() {                         //? from bing // IT worked. 
    COORD topLeft = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    FillConsoleOutputAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE, screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    SetConsoleCursorPosition(console, topLeft);
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        cout << "number " << i << endl;
    }

    for ( int i = 0; i < 1000000; i++) // for wait 
    {
        cout << "";
    }
    
    //CLS;                         //! Failed
    clearConsole();                // worked //~ HOW?  I will learn it no mater how.
    /*
    *According to bing we should use clearconsole(), it is robust solution 
    *As it use console API    
    */


    system("cls");                  // worked //~ It also worked.
    /*
    !According to bing we should not use it as it.
    !in fect we should not use system(); at all
    !reason: https://cplusplus.com/articles/j3wTURfi/

    !What system() does is:
        1) suspend your program
        2) call the operating system
        3) open an operating system shell (relaunches the O/S in a sub-process)
        4) the O/S must now find the PAUSE command
        5) allocate the memory to execute the command
        6) execute the command and wait for a keystroke
        7) deallocate the memory
        8) exit the OS
        9) resume your program
    
    !2) It Is Resource Heavy
    !3) It Defeats Security
    !4) Anti-Virus Programs Hate It

    */
    

    return 0;    
}