#include <iostream>
#include "LoadingAnimation.hpp"

void function1() {
    for (int i = 0; i < 4; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
        std::cout << "\r"; // Clear the loading symbol
        std::cout << "Processing step " << i + 1 << "/4" << std::endl;
    }
}

int function2(int a, int b) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    int sum = a * b;
    std::cout << "\r" << "The sum is: " << sum << std::endl;
    return sum;
}

int main() {
    // Use like this:
    loading_anim(function1);

    // Or like this if the function has parameters:
    int sum = loading_anim(function2, 10, 20);

    // Or even manually like this:
    ConsoleLoadingAnimation anim;
    anim.start();
    function1();
    anim.stop();

    return 0;
}