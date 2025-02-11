cmake_minimum_required(VERSION 3.30)

project(storing_date)

find_package(fmt)
add_executable(storing_date storedate.cpp)
target_link_libraries(storing_date PRIVATE fmt::fmt)