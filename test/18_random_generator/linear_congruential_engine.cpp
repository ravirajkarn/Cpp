#include <iostream>
#include <random>

int main() {
    // Parameters for LCG X_i=((X_(i−1)⋅a)+c)  mod m
    const unsigned int a = 2;
    const unsigned int c = 0;
    const unsigned int m = 10;
    const unsigned int seed = 3;

    // Create the LCG engine
    std::linear_congruential_engine<unsigned int, a, c, m> lcg(seed);

    // Generate and print random numbers
    for (int i = 0; i < 10; ++i) {
        std::cout << lcg() << " " ;
    }

    return 0;
}