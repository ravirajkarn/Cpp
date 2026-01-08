cmake_minimum_required(VERSION 3.15)
project(Asynchronous CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

execute_process(
        COMMAND conan install . --build=missing --profile=profile
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        RESULT_VARIABLE conan_result
        )
if(NOT ${conan_result} EQUAL 0)
    message(FATAL_ERROR "Conan install failed with error code: ${conan_result}")
endif()

include(${CMAKE_BINARY_DIR}/generators/conan_toolchain.cmake)

find_package(fmt REQUIRED)

add_executable(ThreadFunction src/thread_function.cpp)

add_executable(JoiningThread src/JoiningThread.cpp)

# cspell: ignore Mutexxx jthread gaurd
add_executable(Mutexxx src/Mutexxx.cpp)

add_executable(jthread "src/jthread in c++.cpp")

add_executable(ProducerConsumer src/ProducerConsumer.cpp)

add_executable(Running_threads_in_background "src/20 Running threads in the background.cpp")

add_executable(std_async_return_value_from_thread "src/15 std async return value from thread.cpp")

add_executable(future_and_promise "src/14 future and promise.cpp")

add_executable(std_lock "src/10 std lock in c++11.cpp")

add_executable(Producer_Consume_Problem "src/8.0 Producer Consume Problem In C++.cpp")

add_executable(condition_variable "src/7.0 condition variable in c++ threading.cpp")

add_executable(unique_lock "src/6.3 unique_lock in c++.cpp")

add_executable(lock_gaurd "src/6.2 lock_gaurd in c++.cpp")

add_executable(Recursive_Mutex "src/6.1 Recursive Mutex In C++ .cpp")

add_executable(std_try_lock "src/6.0 std try_lock.cpp")

add_executable(try_lock "src/5.0 try_lock in c++ threading.cpp")

add_executable(Timed_Mutex "src/4.1 Timed Mutex In C++.cpp")


