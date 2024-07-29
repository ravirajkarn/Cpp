#include <iostream>
#include <map>
#include <random>

int main() {
    std::random_device rd;
    std::map<int, int> hist;

    for (int n = 0; n < 20000; ++n)
        ++hist[rd() % 10];

    for (const auto& p : hist)
        std::cout << p.first << ": " << std::string(p.second / 100, '*') << '\n';
}
