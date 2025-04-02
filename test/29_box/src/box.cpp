#include <iostream>
#include <string>
#include <fmt/core.h>
#include <fmt/chrono.h>

using namespace std;

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
		{
			if(row == 1 || row == height || column == 1 || column == width)
				cout << "*";
			else
				cout << " ";
		}
		cout << '\n';
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

// online search result

/**
 * @brief Creates a rectangle.
 * 
 * @param height Height of the rectangle.
 * @param width Width of the rectangle.
 */
void box_2(int height, int width) {
    if (height <= 0 || width <= 0) {
        cout << "Invalid dimensions!" << endl;
        return;
    }

    // Construct the top and bottom rows
    string borderRow = string(width, '*');
    // Construct the middle row
    string middleRow = "*" + string(width - 2, ' ') + "*";

    // Print the rectangle
    cout << borderRow << endl; // Top row
    for (int i = 0; i < height - 2; i++) {
        cout << middleRow << endl; // Middle rows
    }
    if (height > 1) {
        cout << borderRow << endl; // Bottom row
    }
}


/**
 * @brief Creates a rectangle. with spice of fmt.
 * 
 * @param height Height of the rectangle.
 * @param width Width of the rectangle.
 */
void box_fmt(int height, int width) {
    if (height <= 0 || width <= 0) {
        fmt::print("Invalid dimensions!\n");
        return;
    }

    // Construct the top and bottom rows
    string borderRow = string(width, '*');
    // Construct the middle row
    string middleRow = "*" + string(width - 2, ' ') + "*";

    // Print the rectangle
    fmt::print("{}\n", borderRow); // Top row
    for (int i = 0; i < height - 2; i++) {
        fmt::print("{}\n", middleRow); // Middle rows
    }
    if (height > 1) {
        fmt::print("{}\n", borderRow); // Bottom row
    }
}


/**
 * @brief Creates a rectangle. new method.
 * 
 * @param height Height of the rectangle.
 * @param width Width of the rectangle.
 */
void box_3(int height, int width) {

    ios_base::sync_with_stdio(false);cin.tie(NULL);

    if (height <= 0 || width <= 0) {
        cout << "Invalid dimensions!" << endl;
        return;
    }

    // Construct the top and bottom rows
    string borderRow = string(width, '*');
    // Construct the middle row
    string middleRow = "*" + string(width - 2, ' ') + "*";

    // Print the rectangle
    cout << borderRow << endl; // Top row
    for (int i = 0; i < height - 2; i++) {
        cout << middleRow << endl; // Middle rows
    }
    if (height > 1) {
        cout << borderRow << endl; // Bottom row
    }
}

int main()
{
	cout << '\n';
	auto start = chrono::high_resolution_clock::now();
	box(5, 10);
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
	fmt::print("Time taken by box function: {} ms\n\n", duration.count());
	
	start = chrono::high_resolution_clock::now();
	box_2(5, 10);
	end = chrono::high_resolution_clock::now();
	duration = chrono::duration_cast<chrono::microseconds>(end - start);
    fmt::print("Time taken by box_2 function: {} ms\n\n", duration.count());
	
	start = chrono::high_resolution_clock::now();
	box_fmt(5, 10);
	end = chrono::high_resolution_clock::now();
	duration = chrono::duration_cast<chrono::microseconds>(end - start);
    fmt::print("Time taken by box_fmt function: {} ms\n\n", duration.count());
	
    start = chrono::high_resolution_clock::now();
	box_3(5, 10);
	end = chrono::high_resolution_clock::now();
	duration = chrono::duration_cast<chrono::microseconds>(end - start);
    fmt::print("Time taken by box_3 function: {} ms\n\n", duration.count());
	
	return 0;
}
