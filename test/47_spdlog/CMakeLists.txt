cmake_minimum_required(VERSION 3.15)
project(spdlog_test CXX)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_BINARY_DIR}/generators/conan_toolchain.cmake")

find_package(spdlog REQUIRED)

add_executable(logtest src/logtest.cpp)
target_link_libraries(logtest spdlog::spdlog)