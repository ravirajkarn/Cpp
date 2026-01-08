// cspell: ignore Mutexxx
/**
 * @file Mutexxx.cpp
 * @author Sumit Kumar (ravirajkarn21@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-07-29
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 /**
  * What is Race Condition and to Solve it?
  * Answer: 
  *  1. Race Condition occurs when multiple threads access shared data and try to change it at the same time.
  *  2. If there is a race condition, then we have to protect it and the protected section is called critical section/region.
  * 
  *  What is Mutex?
  * Answer:
  * 1. Mutex is a mutual exclusion object that allows multiple threads to share the same resource, but not simultaneously.
  * 2. Mutex is used to protect shared data from being accessed by multiple threads at the same time.
  * 3. Mutex is a locking mechanism that ensures that only one thread can access the shared resource at a time.(by lock() and unlock() methods)
  * 
  */

#include <iostream>
#include <thread>
#include <mutex>

int myAmount = 0; // Shared resource
std::mutex myMutex; // Mutex to protect the shared resource

void addMoney(){
    myMutex.lock(); // Lock the mutex to protect the shared resource
    ++myAmount; // Increment the shared resource
    myMutex.unlock(); // Unlock the mutex to allow other threads to access the shared resource
    // Note: It's better to use std::lock_guard or std::unique_lock for exception safety and automatic unlocking.
    // Example: std::lock_guard<std::mutex> lock(myMutex); // Automatically locks the mutex and unlocks it when going out of scope
}

int main() {
    std::thread t1(addMoney);
    std::thread t2(addMoney);

    t1.join(); // Wait for thread t1 to finish
    t2.join(); // Wait for thread t2 to finish

    std::cout << "Final Amount: " << myAmount << std::endl;
    return 0;
}