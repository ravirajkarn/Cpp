#include <iostream>  // for std::cin, std::cout
#include <fmt/core.h> // for fmt::print
#include <fmt/chrono.h> // for fmt::chrono
#include <conio.h> // for _getch()
#include <string>   // for std::string


// original my code
void box(int height, int width) {
    // Input validation
    if (height <= 0 || width <= 0) {
         fmt::print("Height and width must be positive integers.\n");
        return;
    }
    
    
    for (int row = 0; row < height; row++) {
        std::string line;
        int box_place = 0;
        for (int column = 0; column < width; column++) {

            // Precompute boundaries for the inner box
            int top = box_place;
            int left = box_place;
            int right = width - box_place -1;
            int bottom = height - box_place -1  ;

            if ((row == top || row == bottom) && column >= left && column <= right) {
                line = line + std::to_string(bottom+1);
            } else if ((column == left || column == right) && row >= top && row <= bottom) {
                line = line + std::to_string(bottom+1);
            } else {
                line += " ";
            }

            if (column < row)           
                box_place++;
            if (column >= width - row - 1)
                box_place--;
            
        }
         fmt::print("{}\n", line);
    }
}

// Code with the help of internat or AI
void box_2(int height, int width) {
    if (height <= 0 || width <= 0) {
        fmt::print("Height and width must be positive integers.\n");
        return;
    }
    
    std::string line;
    for (int row = 0; row < height; row++) {
        for (int column = 0; column < width; column++) {
            // Determine the layer of the current position
            int layer = std::min({row, column, height - row - 1, width - column - 1});
            line += std::to_string(height - layer);
        }
        line += "\n"; // New line after each row
    }
    fmt::print("{}", line);
}

int main() {
    int side = 0;

    while (true) {
        // Check for key press to exit
        if (_getch() == 27) // ESC key
            break; // Exit the loop

        // Get user input
        std::cin >> side;
        // std::cin >> place;

        // Measure execution time
        auto start = std::chrono::high_resolution_clock::now();
        box_2(side, side);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        // Print execution time
        fmt::print("Time taken by Rectangle function: {} microsecconds\n\n", duration.count());
        
        // Measure execution time
        start = std::chrono::high_resolution_clock::now();
        box(side, side);
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        // Print execution time
        fmt::print("Time taken by Rectangle function: {} microseconds\n\n", duration.count());
    }
    return 0;
}