#include <iostream>
#include <random>

int main() {
    std::subtract_with_carry_engine<unsigned, 32, 16, 31> engine;

    // Generate and print random numbers
    for (int count = 1; count <= 10; ++count) {
        std::cout << engine() << ' ';
    }

    return 0;
}