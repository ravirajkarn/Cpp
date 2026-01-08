#include <iostream>
#include <map>
#include <random>

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dist(1, 50);

    int random_number = dist(gen);
    int random_number2 = dist(gen);

    std::cout << "\nRandom number1 " << random_number << "\nRandom number2 " << random_number2;
    return 0;

}
