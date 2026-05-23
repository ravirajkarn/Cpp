/**
 * @file binary_search.cpp
 * @author Sumit Kumar (ravirajkarn@outlook.com)
 * @brief This is binary search algorithm created my me.
 * @version 0.1
 * @date 2026-05-20
 *
 * @copyright Copyright (c) 2026
 *
 */

#include <print>
#include <search_in_rotated_sorted_array.hpp>

using namespace std;

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    return me::rotatedArray(nums, target);
  }
};

int main() {
  Solution Rsa;
  std::vector<int> number = {-1, 0, 3, 5, 9, 12};
  int target = 9;
  print("the numbe is: {}\n", Rsa.search(number, target));
  return 0;
}
