#include <fmt/core.h>
#include <vector>
#include <string>
#include "P_C.h"
#include "permutation.hpp"

int main() {

    fmt::print("Permutation P(4,4): {}\n", p(4, 4));
    fmt::print("Factorial of 5: {}\n", fact(5));
    fmt::print("Combination C(5, 3): {}\n", c(5, 3));

    std::vector<std::string> test = {"A", "B", "C"};

    auto parmute = permutation(test);

    for(const auto& temp : parmute)
    fmt::print("{}\n", temp);

    fmt::print("\n\n newline \n\n");

    auto parmute_w_r = permutation_(test, test.size());
    for(const auto& temp : parmute_w_r)
    fmt::print("{}\n", temp);

    return 0;
}