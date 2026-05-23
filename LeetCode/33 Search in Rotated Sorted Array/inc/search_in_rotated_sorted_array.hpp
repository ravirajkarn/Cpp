#pragma once
#include <vector>

/**
 * @brief This i originally created by me. My pure logic building without any
 * help, and I am proud of it.
 *
 */
namespace me {
int binarySearch(const std::vector<int>& nums, int left = 0, int right = 0,
                 int target = 0) {
  if (nums.empty()) return -1;
  int mid = (left + right) / 2;
  while (left <= right && target >= nums.at(left) && target <= nums.at(right)) {
    if (nums.at(mid) != target) {
      if (nums.at(mid) <= target)
        left = mid;
      else
        right = mid;
      mid = (left + right) / 2;
      if (nums.at(left) == target) return left;
      if (nums.at(right) == target) return right;
      if (left == mid) break;
    } else
      return mid;
  }
  return -1;
}

int rotatedArray(std::vector<int>& nums, const int target) {
  if (nums.empty()) return -1;

  int left = 0;
  int right = nums.size() - 1;
  int mid = (left + right) / 2;

  while (left <= right) {
    if (nums.at(left) == target) return left;
    if (nums.at(right) == target) return right;
    if (nums.size() < 3) break;  // single and double elements

    mid = (left + right) / 2;
    if (left == mid || mid == right) break;

    if (nums.at(mid) > nums.at(left) && nums.at(mid) > nums.at(right)) {
      if (nums.at(left) < target && target < nums.at(mid)) {
        return binarySearch(nums, left, mid, target);
      } else {
        left = mid;
      }
    } else if (nums.at(mid) < nums.at(left) && nums.at(mid) < nums.at(right)) {
      if (nums.at(mid) < target && target < nums.at(right)) {
        return binarySearch(nums, mid, right, target);
      } else {
        right = mid;
      }
    } else
      return binarySearch(nums, left, right, target);
  }

  return -1;
}
}  // namespace me

namespace google {
int rotatedArray(std::vector<int>& nums, int target) {
  int left = 0;
  int right = nums.size() - 1;

  while (left <= right) {
    // Prevents integer overflow compared to (left + right) / 2
    int mid = left + (right - left) / 2;

    if (nums[mid] == target) {
      return mid;
    }

    // Condition 1: Left half is sorted
    if (nums[left] <= nums[mid]) {
      // Check if target is strictly within the sorted left half
      if (nums[left] <= target && target < nums[mid]) {
        right = mid - 1;  // Target must be in the left half
      } else {
        left = mid + 1;  // Target must be in the right half
      }
    }
    // Condition 2: Right half is sorted
    else {
      // Check if target is strictly within the sorted right half
      if (nums[mid] < target && target <= nums[right]) {
        left = mid + 1;  // Target must be in the right half
      } else {
        right = mid - 1;  // Target must be in the left half
      }
    }
  }

  return -1;  // Target not found
}
}  // namespace google