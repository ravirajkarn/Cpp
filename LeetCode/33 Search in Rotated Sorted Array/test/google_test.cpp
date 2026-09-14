#include <gtest/gtest.h>

#include <algorithm>
#include <search_in_rotated_sorted_array.hpp>
#include <vector>

TEST(GeminiTesting, EmptyArray) {
  std::vector<int> num = {};
  EXPECT_EQ(google::rotatedArray(num, 5), -1);
}

TEST(GeminiTesting, SingleElement) {
  std::vector<int> num = {5};
  EXPECT_EQ(google::rotatedArray(num, 5), 0);
  EXPECT_EQ(google::rotatedArray(num, 2), -1);
}

TEST(GeminiTesting, TwoElementsUnrotated) {
  std::vector<int> num = {1, 3};
  EXPECT_EQ(google::rotatedArray(num, 1), 0);
  EXPECT_EQ(google::rotatedArray(num, 3), 1);
  EXPECT_EQ(google::rotatedArray(num, 2), -1);
}

TEST(GeminiTesting, TwoElementsRotated) {
  std::vector<int> num = {3, 1};
  EXPECT_EQ(google::rotatedArray(num, 3), 0);
  EXPECT_EQ(google::rotatedArray(num, 1), 1);
  EXPECT_EQ(google::rotatedArray(num, 0), -1);
}

TEST(GeminiTesting, PivotInMiddleTargetLeft) {
  std::vector<int> num = {4, 5, 6, 7, 0, 1, 2};
  EXPECT_EQ(google::rotatedArray(num, 4), 0);
  EXPECT_EQ(google::rotatedArray(num, 6), 2);
}

TEST(GeminiTesting, PivotInMiddleTargetRight) {
  std::vector<int> num = {4, 5, 6, 7, 0, 1, 2};
  EXPECT_EQ(google::rotatedArray(num, 1), 5);
  EXPECT_EQ(google::rotatedArray(num, 2), 6);
}

TEST(GeminiTesting, PivotInMiddleTargetPeakAndValley) {
  std::vector<int> num = {4, 5, 6, 7, 0, 1, 2};
  EXPECT_EQ(google::rotatedArray(num, 7), 3);
  EXPECT_EQ(google::rotatedArray(num, 0), 4);
}

TEST(GeminiTesting, PivotInMiddleTargetMissing) {
  std::vector<int> num = {4, 5, 6, 7, 0, 1, 2};
  EXPECT_EQ(google::rotatedArray(num, 3), -1);
  EXPECT_EQ(google::rotatedArray(num, 8), -1);
  EXPECT_EQ(google::rotatedArray(num, -2), -1);
}

TEST(GeminiTesting, RightHalfLonger) {
  std::vector<int> num = {6, 7, 0, 1, 2, 3, 4, 5};
  EXPECT_EQ(google::rotatedArray(num, 0), 2);
  EXPECT_EQ(google::rotatedArray(num, 4), 6);
}

TEST(GeminiTesting, RotatedByOneRight) {
  std::vector<int> num = {7, 1, 2, 3, 4, 5, 6};
  EXPECT_EQ(google::rotatedArray(num, 7), 0);
  EXPECT_EQ(google::rotatedArray(num, 1), 1);
  EXPECT_EQ(google::rotatedArray(num, 4), 4);
}

TEST(GeminiTesting, RotatedByOneLeft) {
  std::vector<int> num = {2, 3, 4, 5, 6, 7, 1};
  EXPECT_EQ(google::rotatedArray(num, 1), 6);
  EXPECT_EQ(google::rotatedArray(num, 7), 5);
  EXPECT_EQ(google::rotatedArray(num, 2), 0);
}

TEST(GeminiTesting, UnrotatedArray) {
  std::vector<int> num = {1, 2, 3, 4, 5, 6, 7};
  EXPECT_EQ(google::rotatedArray(num, 1), 0);
  EXPECT_EQ(google::rotatedArray(num, 4), 3);
  EXPECT_EQ(google::rotatedArray(num, 7), 6);
  EXPECT_EQ(google::rotatedArray(num, 8), -1);
}

TEST(LeetCodeTesting, Example1) {
  std::vector<int> num = {4, 5, 6, 7, 0, 1, 2};
  EXPECT_EQ(google::rotatedArray(num, 0), 4);
}

TEST(LeetCodeTesting, Example2) {
  std::vector<int> num = {4, 5, 6, 7, 0, 1, 2};
  EXPECT_EQ(google::rotatedArray(num, 3), -1);
}

TEST(LeetCodeTesting, Example3) {
  std::vector<int> num = {1};
  EXPECT_EQ(google::rotatedArray(num, 0), -1);
}