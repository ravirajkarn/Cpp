/**
 * @file Q1.cpp
 * @author Sumit Kumar (ravirajkarn21@gmail.com)
 * @details  Write a C++ program that reads a maximum of 100 integers from the keyboard,
 *           stores them in a long array, sorts the integers in ascending order, and displays
 *           sorted output. Input can be terminated by any invalid input, such as a letter.
 * @version 0.1
 * @date 2025-06-08
 *
 * @copyright Copyright (c) 2025
 *
**/

#include "bubble_sort.hpp"
#include <fmt/core.h>
#include <iostream>
#include <fmt/color.h>
#include <algorithm>

int main()
{

    std::vector<int> data;
    std::string num;
    fmt::print("Enter numbers (It must be less then 100):\n");
    for (int i = 0; i <= 100; ++i)
    {
        if (std::getline(std::cin, num) && std::all_of(num.begin(), num.end(), ::isdigit))
        {
            if (num.empty())
            {
                break;
            }
            data.push_back(std::stoi(num));
            std::cin.clear(); // Clear the error state of cin
        }
    }

    BUBBLE_SORT bubble(data);

    for (const auto &num : data)
    {
        fmt::print("{} ", num);
    }

    return 0;
}