// ball.cpp
// Simultes a bouncing ball 
// ---------------------------------------------------------------------------------
// Windows does not support ANSI escape sequence 

#include <iostream>
#include <string>
//#include <windows.h>

using namespace std;

#define DELAY 10000000L             //Output delay
#define CLS (cout<< "\033[2J")      //Clear screen
#define LOCATE(z,s) (cout << "\033[" << z << ';' << s << 'H')
        // Position the cursor in row z and column s

/*
void color(int color = 0x07) //use to change color of console
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
*/

int main()
{

    //color(01);
    int x = 2, y = 3, dx = 1, speed =0;
    string floor(79, '-'), header = "*****  JUMPING BALL  *****";

    CLS;
    LOCATE(1,25);   cout << header;
    LOCATE(25,1);   cout << floor;

    while (true)        // Let the ball "always" bounce
    {                   // Terminate by interrupt key (^C)
        LOCATE(y,x); cout << 'o' << endl; // Show the ball
        for( long wait = 0; wait < DELAY; ++wait );
        
        if (x==1|| x== 79) dx = -dx;            // Bounce off
                                                // a wall?
        if(y== 24)                              // On the floor?
        {
            speed = - speed;
            if (speed == 0)
            {
                speed = -7;                     //Restart
            }
        }
        speed += 1;
        LOCATE(y,x); cout << ' ';
        y += speed; x += dx;
    }
}