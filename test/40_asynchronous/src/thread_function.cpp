/**
 * @file main.cpp
 * @author Sumit Kumar (ravirajkarn@outlook.com)
 * @brief Demonstrates multiple ways to create threads in C++.
 * @version 0.1
 * @date 2025-07-23
 *
 * @copyright Copyright (c) 2025
 *
 * @details
 * ============================================================================
 * THREADING IN C++: KEY POINTS
 * ============================================================================
 * 1. What is a thread?
 *    - A thread is a lightweight process. Every C++ program starts with a main thread (main()).
 *    - Threads allow parallel execution of code, improving performance and responsiveness.
 *
 * 2. Why use threads?
 *    - To perform multiple tasks simultaneously (e.g., handling user input while processing data).
 *    - To utilize multi-core CPUs efficiently.
 *
 * 3. Real-world examples:
 *    - Web server: One thread handles requests, another processes data.
 *    - Video game: One thread renders graphics, another handles input.
 *    - Browser: Each tab can be a separate thread.
 *    - VS Code: Threads for code completion (Intellisense).
 *
 * 4. Ways to create threads in C++:
 *    - Function pointers
 *    - Lambda expressions
 *    - Functors (objects with operator())
 *    - Member functions (non-static)
 *    - Static member functions
 *
 * 5. This program demonstrates all five methods by calculating the sum of even and odd numbers
 *    in a large range using two threads for each method.
 *
 * 6. Key implementation notes:
 *    - Global variables EvenSum and OddSum are used for results.
 *    - Each method resets these sums before starting.
 *    - No synchronization is needed here because each thread writes to a separate variable.
 *    - Execution time for each method is measured and printed.
 * ============================================================================
 */

#include <iostream>
#include <thread>
#include <chrono>
#include <cstdint>

constexpr uint64_t RANGE_START = 1;
constexpr uint64_t RANGE_END = 1900000000;

uint64_t EvenSum = 0;
uint64_t OddSum = 0;

// -----------------------------------------------------------------------------
// 1. Function pointer example
// -----------------------------------------------------------------------------
/**
 * @brief Adds all even numbers in the given range to EvenSum.
 */
void findEven(uint64_t start, uint64_t end) {
    for (uint64_t i = start; i <= end; ++i)
        if ((i & 1) == 0) EvenSum += i;
}

/**
 * @brief Adds all odd numbers in the given range to OddSum.
 */
void findOdd(uint64_t start, uint64_t end) {
    for (uint64_t i = start; i <= end; ++i)
        if (i & 1) OddSum += i;
}

/**
 * @brief Demonstrates threading using function pointers.
 */
void thread_with_function_pointers() {
    EvenSum = OddSum = 0;
    auto startTime = std::chrono::high_resolution_clock::now();

    // Launch two threads: one for even, one for odd
    std::thread evenThread(findEven, RANGE_START, RANGE_END);
    std::thread oddThread(findOdd, RANGE_START, RANGE_END);

    // Wait for both threads to finish
    evenThread.join();
    oddThread.join();

    auto duration = std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - startTime);
    std::cout << "Function pointers:\n";
    std::cout << "Even sum: " << EvenSum << "\nOdd sum: " << OddSum << "\nTime: " << duration.count() << "s\n";
}

// -----------------------------------------------------------------------------
// 2. Lambda expression example
// -----------------------------------------------------------------------------
/**
 * @brief Demonstrates threading using lambda expressions.
 */
void thread_with_lambda_expressions() {
    EvenSum = OddSum = 0;
    auto startTime = std::chrono::high_resolution_clock::now();

    std::thread evenThread([](uint64_t s, uint64_t e) {
        for (uint64_t i = s; i <= e; ++i)
            if ((i & 1) == 0) EvenSum += i;
    }, RANGE_START, RANGE_END);

    std::thread oddThread([](uint64_t s, uint64_t e) {
        for (uint64_t i = s; i <= e; ++i)
            if (i & 1) OddSum += i;
    }, RANGE_START, RANGE_END);

    evenThread.join();
    oddThread.join();

    auto duration = std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - startTime);
    std::cout << "Lambda expressions:\n";
    std::cout << "Even sum: " << EvenSum << "\nOdd sum: " << OddSum << "\nTime: " << duration.count() << "s\n";
}

// -----------------------------------------------------------------------------
// 3. Functor (function object) example
// -----------------------------------------------------------------------------
/**
 * @brief Functor class for even/odd sum calculation.
 */
class EvenOddFunctor {
public:
    void operator()(uint64_t start, uint64_t end, bool isEven) {
        if (isEven) {
            for (uint64_t i = start; i <= end; ++i)
                if ((i & 1) == 0) EvenSum += i;
        } else {
            for (uint64_t i = start; i <= end; ++i)
                if (i & 1) OddSum += i;
        }
    }
};

/**
 * @brief Demonstrates threading using a functor object.
 */
void thread_with_functor_object() {
    EvenSum = OddSum = 0;
    auto startTime = std::chrono::high_resolution_clock::now();

    EvenOddFunctor functor;
    std::thread evenThread(std::ref(functor), RANGE_START, RANGE_END, true);
    std::thread oddThread(std::ref(functor), RANGE_START, RANGE_END, false);

    evenThread.join();
    oddThread.join();

    auto duration = std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - startTime);
    std::cout << "Functor object:\n";
    std::cout << "Even sum: " << EvenSum << "\nOdd sum: " << OddSum << "\nTime: " << duration.count() << "s\n";
}

// -----------------------------------------------------------------------------
// 4. Non-static member function example
// -----------------------------------------------------------------------------
/**
 * @brief Class with non-static member functions for even/odd sum.
 */
class EvenOddMember {
public:
    void findEven(uint64_t start, uint64_t end) {
        for (uint64_t i = start; i <= end; ++i)
            if ((i & 1) == 0) EvenSum += i;
    }
    void findOdd(uint64_t start, uint64_t end) {
        for (uint64_t i = start; i <= end; ++i)
            if (i & 1) OddSum += i;
    }
};

/**
 * @brief Demonstrates threading using non-static member functions.
 */
void thread_with_non_static_member_function() {
    EvenSum = OddSum = 0;
    auto startTime = std::chrono::high_resolution_clock::now();

    EvenOddMember obj;
    std::thread evenThread(&EvenOddMember::findEven, &obj, RANGE_START, RANGE_END);
    std::thread oddThread(&EvenOddMember::findOdd, &obj, RANGE_START, RANGE_END);

    evenThread.join();
    oddThread.join();

    auto duration = std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - startTime);
    std::cout << "Non-static member functions:\n";
    std::cout << "Even sum: " << EvenSum << "\nOdd sum: " << OddSum << "\nTime: " << duration.count() << "s\n";
}

// -----------------------------------------------------------------------------
// 5. Static member function example
// -----------------------------------------------------------------------------
/**
 * @brief Class with static member functions for even/odd sum.
 */
class EvenOddStatic {
public:
    static void evenSum(uint64_t end) {
        for (uint64_t i = 0; i <= end; ++i)
            if ((i & 1) == 0) EvenSum += i;
    }
    static void oddSum(uint64_t end) {
        for (uint64_t i = 0; i <= end; ++i)
            if (i & 1) OddSum += i;
    }
};

/**
 * @brief Demonstrates threading using static member functions.
 */
void thread_with_static_member_function() {
    EvenSum = OddSum = 0;
    auto startTime = std::chrono::high_resolution_clock::now();

    std::thread evenThread(&EvenOddStatic::evenSum, RANGE_END);
    std::thread oddThread(&EvenOddStatic::oddSum, RANGE_END);

    evenThread.join();
    oddThread.join();

    auto duration = std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - startTime);
    std::cout << "Static member functions:\n";
    std::cout << "Even sum: " << EvenSum << "\nOdd sum: " << OddSum << "\nTime: " << duration.count() << "s\n";
}

// -----------------------------------------------------------------------------
// Main function: runs all threading demonstrations
// -----------------------------------------------------------------------------
int main() {
    thread_with_function_pointers();
    thread_with_lambda_expressions();
    thread_with_functor_object();
    thread_with_non_static_member_function();
    thread_with_static_member_function();
    return 0;
}