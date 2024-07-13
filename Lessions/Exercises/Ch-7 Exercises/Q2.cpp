/*
Modify the program ball1.cpp to
a. display a white ball on a blue background,
b. terminate the program when the Esc key is pressed,
c. increase the speed of the ball with the + key and decrease the speed
with the – key.
You will need the functions kbhit() and getch() (shown opposite) to solve
parts b and c of this problem.
*/

/*
■EXERCISES
Hints for Exercise 2
You can use the function kbhit() to test whether the user has pressed a key. If
so, the function getch() can be used to read the character.This avoids
interrupting the program when reading from the keyboard.
These functions have not been standardized by ANSI but are available on
almost every system. Both functions use operating system routines and are
declared in the header file conio.h.
The function kbhit()
Prototype: int kbhit();
Returns: 0, if no key was pressed, otherwise != 0.
When a key has been pressed, the corresponding character can be read by
getch().
The function getch()
Prototype: int getch();
Returns: The character code.There is no special return value on reaching
end-of-file or if an error occurs.
In contrast to cin.get(), getch() does not use an input buffer when
reading characters, that is, when a character is entered, it is passed directly to
the program and not printed on screen. Additionally, control characters, such as
return ( = 13), Ctrl+Z ( = 26), and Esc ( = 27), are passed to the program “as is.”

Example: 
int c;
if( kbhit() != 0)  // Key was pressed?
{
c = getch();    // Yes -> Get character
if( c == 27 )   // character == Esc?
// . . .
}

✓NOTE
When a function key, such as F1, F2, ..., Ins, Del, etc. was pressed, the function
getch() initially returns 0. A second call yields the key number.
*/

#include <iostream>
#include <windows.h>
#include <conio.h>
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

        if (kbhit() != 0)
        {
            if (getch() == 27)
            {
                return 0;
            }
            else if(getch() == 43) //  "+"
            {
                speed = speed + 1;
                //goto start;
            }
            else if(getch() == 45)  // "-"
            {
                speed = speed - 1;
                //goto start;
            }
            else ;
                //goto start;
        }
        else ;

        clearConsole();
        LOCATION(1,25,header);         
        LOCATION(y,x,"o");                      // Show the ball

        if (x==1|| x== 79) dx = -dx;            // Bounce off
                                                // a wall?
        if(y >= 24)                             // On the floor?
        {
            y=24;
            speed = - speed;
            if (speed == 0)
            {
                speed = -7;                     //Restart
            }
        }
        
        LOCATION(25 - y + 1 ,1,floor);  

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
