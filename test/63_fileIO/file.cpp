#include <filesystem>
#include <fstream>
#include <print>
#include <vector>
// #include <iostream>

int main() try {
  if (!std::filesystem::exists(std::filesystem::current_path() / "data.txt")) {
    std::print("file not exist!\n");
    return 1;
  }

  std::ifstream file(
      std::filesystem::path(std::filesystem::current_path() / "data.txt"));
  std::vector<int> data;
  std::string token;
  while (std::getline(file, token, ',')) {
    data.push_back(std::stoi(token));
  }

  for (const auto& i : data) {
    std::print("{}\n", i);
  }
} catch (const std::exception& e) {
  std::print(stderr, "{}", e.what());
}