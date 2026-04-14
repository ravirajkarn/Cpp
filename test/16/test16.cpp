/**
 * @file test16.cpp
 * @author Sumit Kumar
 * @brief This test is conducting to check continuous simultaneous output and input.
 * @version 0.1
 * @date 2024-06-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <fmt/core.h>
#include <iostream>

void test1(void){
    int a, b, c;
    std::string aa, bb, cc;

    std::cout << "\nHello Sumit how are you? ";
    std::getline(std::cin, aa);
    std::cout << "Dont you think you progressing in you journey? ";
    std::cin >> bb;
    std::cout << "You have come to far, Do you know that?(1/0)? ";
    std::cin >> a;
    std::cout << "Be proud on your self.(1/0) ";
    std::cin >> b;
    std::cout << "Keep moving foreword.(1) ";
    std::cin >> c;
    std::cout << "रधो रधो";
    std::cin >> cc;
}

void test2(void){
    int a, b, c;
    std::string aa, bb, cc;

    fmt::print("\nHello Sumit how are you? ");
    std::getline(std::cin, aa);
    fmt::print("Dont you think you progressing in you journey? ");
    std::cin >> bb;
    fmt::print("You have come to far, Do you know that?(1/0)? ");
    std::cin >> a;
    fmt::print("Be proud on your self.(1/0) ");
    std::cin >> b;
    fmt::print("Keep moving foreword.(1) ");
    std::cin >> c;
    fmt::print("रधो रधो");
    std::cin >> cc;
}

int main(){

    // test1();

    test2();

    return 0;
}