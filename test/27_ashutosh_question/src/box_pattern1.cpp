#include <fmt/core.h>
#include <fmt/color.h>
#include <fmt/chrono.h>
#include <iostream>
#include <string>

/**
 * @brief Creates a rectangle or square pattern with optional inner box placement.
 * 
 * @param height Height of the rectangle.
 * @param width Width of the rectangle.
 * @param box_place Offset for the inner box placement (default is 0).
 */
void box(int height, int width, int box_place = 0) {
    // Input validation
    if (height <= 0 || width <= 0) {
        std::cout << "Height and width must be positive integers.\n";
        return;
    }
    if (box_place < 0 || box_place >= height || box_place >= width) {
        std::cout << "Invalid box_place value.\n";
        return;
    }

    // Precompute boundaries for the inner box
    int top = box_place + 1;
    int bottom = height - box_place;
    int left = box_place + 1;
    int right = width - box_place;

    for (int row = 1; row <= height; row++) {
        std::string line;
        for (int column = 1; column <= width; column++) {
            if ((row == top || row == bottom) && column >= left && column <= right) {
                line += " * ";
            } else if ((column == left || column == right) && row >= top && row <= bottom) {
                line += " * ";
            } else {
                line += "   ";
            }
        }
        std::cout << line << "\n";
    }
}

/**
 * @brief Creates a square pattern with optional inner box placement.
 * 
 * @param side Side length of the square.
 * @param box_place Offset for the inner box placement (default is 0).
 */
void square(int side, int box_place = 0) {
    box(side, side, box_place);
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

//! fastest box3 function
void box3(int height, int width, int box_place = 0) {
    // Input validation
    if (height <= 0 || width <= 0) {
         fmt::print("Height and width must be positive integers.\n");
        return;
    }
    if (box_place < 0 || box_place >= height || box_place >= width) {
         fmt::print("Invalid box_place value.\n");
        return;
    }

    // Precompute boundaries for the inner box
    int top = box_place + 1;
    int bottom = height - box_place;
    int left = box_place + 1;
    int right = width - box_place;

    for (int row = 1; row <= height; row++) {
        std::string line;
        for (int column = 1; column <= width; column++) {
            if ((row == top || row == bottom) && column >= left && column <= right) {
                line += " * ";
            } else if ((column == left || column == right) && row >= top && row <= bottom) {
                line += " * ";
            } else {
                line += "   ";
            }
        }
         fmt::print("{}\n", line);
    }
}


int main() {
    // Example usage

    auto start = std::chrono::high_resolution_clock::now();
	box(10, 20, 2);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    fmt::print("Time taken by Rectangle function: {} ms\n\n", duration.count());
    
    start = std::chrono::high_resolution_clock::now();
	square(10, 2);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    fmt::print("Time taken by Square function: {} ms\n\n", duration.count());
    
    start = std::chrono::high_resolution_clock::now();
	box2(10, 20, 2);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    fmt::print("Time taken by Square function: {} ms\n\n", duration.count());
    
    start = std::chrono::high_resolution_clock::now();
	box3(10, 20, 2);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    fmt::print("Time taken by Square function: {} ms\n\n", duration.count());

    return 0;
}