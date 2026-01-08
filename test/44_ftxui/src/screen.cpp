// cspell: ignore ftxui
#include <iostream>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <thread>
 
int main() {
    auto screen = ftxui::Screen::Create(
        ftxui::Dimension::Full(),   // Use full terminal width
        ftxui::Dimension::Full()
        // ftxui::Dimension::Fixed(10) // Fixed height of 10 rows
    );
 
    // Access a specific pixel at (10, 5)
    auto& pixel = screen.PixelAt(10, 5);
 
    // Set properties of the pixel.
    pixel.character = U'X';
    pixel.foreground_color = ftxui::Color::Red;
    pixel.background_color = ftxui::Color::RGB(0, 255, 0);
    pixel.bold = true; // Set bold style
    pixel.italic = true;
    screen.Print(); // Print the screen to the terminal
    std::cout << screen.ToString();
    return 0;
}