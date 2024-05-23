//! This is wndows version of ball1.cpp

#include <iostream>
#include <windows.h>
#include "position.h"

void clearConsole();

#define DELAY 9000000            //Output delay

using namespace std;

int main()
{
    int x = 2, y = 3, dx = 1, speed = 0;
    string floor(79*2, '-'), header = "*****  JUMPING BALL  *****";
    
    while (true)        // Let the ball "always" bounce
    {                   // Terminate by interrupt key (^C)
        clearConsole();
        LOCATION(1,25,header);         
        LOCATION(y,x,"o");                      // Show the ball

        if (x==1|| x== 79) dx = -dx;            // Bounce off
                                                // a wall?
        if(y == 24)                             // On the floor?
        {
            speed = - speed;
            if (speed == 0)
            {
                speed = -7;                     //Restart
            }
        }
        
        LOCATION(25 - y + 1 ,1,floor);   //cout << floor;

        //cin.get();

        for( long wait = 0; wait < DELAY; ++wait );

        speed += 1;
        y += speed; x += dx;
    }

}

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
