#include <iostream>
#include <random>

int main() {
    // Create a random device to seed the Mersenne Twister
    std::random_device rd;
    std::mt19937 eng(rd()); // Instantiate a 32-bit Mersenne Twister

    // Generate random numbers
    for (int count = 1; count <= 10; ++count) {
        std::cout << eng() << '\t'; // Generate a random number
        if (count % 5 == 0)
            std::cout << '\n'; // Start a new row after 5 numbers
    }

    return 0;
}
