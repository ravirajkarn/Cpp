#include <iostream>

int BinarySearch(const int Data[], int min, int mid, int max, int target) {
  if (Data[mid] == target) {
    return mid;
  }

  mid = min + (max - min) / 2;
  if (Data[mid] >= target)
    return BinarySearch(Data, min, mid, mid - 1, target);
  else
    return BinarySearch(Data, mid + 1, mid, max, target);
}

int main() {
  int min = 0, mid = 0, max = 9, target = 8;
  int Data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  std::cout << BinarySearch(Data, min, mid, max, target);
}