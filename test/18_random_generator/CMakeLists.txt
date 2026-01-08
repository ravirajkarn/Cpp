cmake_minimum_required(VERSION 3.15)
project(random_generator)

# adding linear_congruential_engine
add_executable(linear_congruential_engine linear_congruential_engine.cpp)

# adding mersenne_twister_engine
add_executable(mersenne_twister_engine mersenne_twister_engine.cpp)

# adding subtract_with_carry_engine
add_executable(subtract_with_carry_engine subtract_with_carry_engine.cpp)

# add random_device
add_executable(random_device1 random_device1.cpp)
add_executable(random_device2 random_device2.cpp)
add_executable(random_device3 random_device3.cpp)
