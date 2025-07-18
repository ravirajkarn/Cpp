#include <iostream>
#include "util.h" // Include our utility header

int main() {
    std::cout << getPlatformMessage() << std::endl;
    std::cout << "This is a multi-platform C++ application." << std::endl;
    return 0;
}