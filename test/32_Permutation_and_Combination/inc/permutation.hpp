#ifndef _PERMUTATION_HPP_
#define _PERMUTATION_HPP_

#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

std::vector<std::string> permutation(std::vector<std::string> &set)
{
    std::sort(set.begin(), set.end());
    std::vector<std::string> result;
    std::ostringstream element;
    do
    {
        element.str("");
        element.clear();

        for (const auto &temp : set)
            element << temp << " ";

        result.push_back(element.str());

    } while (std::next_permutation(set.begin(), set.end()));

    return result;
}

std::vector<std::string> permutation_w_repetition(std::vector<std::string> &set, int k, std::vector<std::string> &currentpermutation)
{
    std::vector<std::string> result;
    std::ostringstream single_string;

    if (k == 0)
    {
        for (const auto &str : currentpermutation)
            single_string << str << " ";
        result.push_back(single_string.str());
        single_string.str(""); // Corrected reset
        single_string.clear();
        return result; // Return result here
    }

    for (const auto &element : set)
    {
        currentpermutation[currentpermutation.size() - k] = element;
        auto sub_result = permutation_w_repetition(set, k - 1, currentpermutation);
        result.insert(result.end(), sub_result.begin(), sub_result.end());
    }

    return result; // Ensure result is returned
}

std::vector<std::string> permutation_(std::vector<std::string> &set, int length)
{
    if (length <= 0 || length > set.size())
    {
        return {}; // Return an empty vector for invalid lengths
    }

    std::vector<std::string> currentpermutation(length);
    return permutation_w_repetition(set, length, currentpermutation);
}

#endif