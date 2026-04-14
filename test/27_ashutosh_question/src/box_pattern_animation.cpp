#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/chrono.h>
#include <iostream>
#include <windows.h>
#include <thread>

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

/**
 * @brief creating rectangle
 * 
 * @param height height of the rectangle
 * @param width width of the rectangle
 */
void box(int height, int width){
	for(int row = 1; row <= height ; row++)
	{
		for(int column = 1; column <= width; column++)
			if( column == width || row == height || column == 1 || row == 1 )
                fmt::print(fmt::fg(fmt::color::red), " * ");
			else
                fmt::print("   ");
        fmt::print("\n");
	}
}

/**
 * @brief creating square
 * 
 * @param side side of the square
 */
void box(int side){
	box(side, side);
}

void pattern1(){
    while(true)
    for(int i = 0; i < 10; ++i) {
        box(i); // square
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        clearConsole(); // clear console
        if(i == 9) {
            for(; i > 1; --i) {
                box(i); // square
                std::this_thread::sleep_for(std::chrono::milliseconds(200));
                clearConsole(); // clear console
            }
        }
    }
    
}

void box2(int height, int width, int box_place=0){
	for(int row = 1; row <= height ; row++)
	{
		for(int column = 1; column <= width; column++)
			if(((row == box_place || row == height - box_place + 1) && column >=box_place && column <= width - box_place + 1) || ((column == box_place || column == width - box_place + 1) && row >=box_place && row <= height - box_place + 1) )
                fmt::print(fmt::fg(fmt::color::red), " * ");
			else
                fmt::print("   ");
        fmt::print("\n");
	}
}

void pattern2(){
    int a = 20;
    while(true)
    for(int i = 0; i < a/2+1; ++i) {
        box2(a,a,i); // square
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        clearConsole(); // clear console
        if(i == a/2) {
            for(; i > 1; --i) {
                box2(a,a,i); // square
                std::this_thread::sleep_for(std::chrono::milliseconds(200));
                clearConsole(); // clear console
            }
        }
    }
}

int main() {
    int n;
    fmt::print(fmt::fg(fmt::color::green), "we have two pattern animation (choose 1 or 2): \n");
    std::cin >> n;
    if(n == 1) {
        pattern1();
    } else if(n == 2) {
        pattern2();
    } else {
        fmt::print(fmt::fg(fmt::color::red), "Invalid choice. Please choose 1 or 2.\n");
    }
    return 0;
}