/**
 * @file JoiningThread.cpp
 * @author Sumit Kumar (ravirajkarn@outlook.com)
 * @brief use and ways to use join(), detach() and joinable() methods of std::thread
 * @version 0.1
 * @date 2025-07-25
 * 
 * @copyright Copyright (c) 2025
 * 
 * 
 * @details This file contains the implementation of a JoiningThread class that encapsulates the behavior of
 * a thread that can be joined or detached. It provides methods to start the thread, join it, and check if it is joinable.
 * 
 */

 /**
  ** JOIN NOTES
  * 0. Once a thread is started we wait for this thread to finish by calling join() function on thread object.
  * 1. If we call join() on a thread that has already been joined or detached, it will throw std::system_error.
  * 2. Double join will result into program termination.
  * 3. If needed we should check thread is joinable before joinin. ( using joinable() function)
  * 4. If a thread is joined, the parent thread will wait for it to finish before continuing execution.
  * 5. After a thread is joined, it cannot be joined again.
  * 6. Joining a thread ensures that the resources used by the thread are released once it completes execution.
  * 
  * * DETACH NOTES
  * 0. This is used to detach newly created thread from the parent thread.
  * 1. Always check before detaching a thread that it is joinable otherwise we may end up double detaching and double detach() will result into program termination.
  * 2. Once a thread is detached, it cannot be joined again.
  * 3. After detaching a thread, the thread will continue to run independently and the parent thread will not wait for it to finish.
  * 4. If a detached thread completes before the parent thread, the resources used by the detached thread will be automatically released. 
  * 5. If the parent thread exits before the detached thread, the detached thread will continue to run until it completes.
  * 6. If a detached thread accesses resources that are no longer valid (e.g., variables that go out of scope), it can lead to undefined behavior.
  * 7. It is important to ensure that any resources accessed by a detached thread remain valid for the lifetime of the thread.
  * 8. Detaching a thread is useful when you want the thread to run independently without blocking the parent thread, and you do not need to synchronize with the thread's completion.
  * 9. If a detached thread throws an exception, it will terminate the program unless the exception is caught within the thread itself.
  * 
  * ~ NOTEs:
  * ~ Either join() or detach() must be called on a thread before it goes out of scope.
  * ~ If neither join() nor detach() is called, the program will terminate with a runtime error.
  * ~ It is a good practice to always check if a thread is joinable before calling join() or detach() to avoid runtime errors.
  * ~ Using join() is generally preferred when you need to synchronize with the thread's completion and ensure that resources are released properly.
  * ~ Using detach() is preferred when you want the thread to run independently and do not need to synchronize with its completion.
  * 
  */

#include <iostream>
#include <chrono>
#include <thread>

void run(int count) {
    while (count --> 0)
        std::cout << "run(int count)\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
}

void joinFun() {
    std::thread t1(run, 10); // Create a thread that runs the function 'run' with argument 10
    std::cout << "joinFun() thread is running\n";
    t1.join(); // Wait for the thread t1 to finish execution

    // t1.join(); // This will cause a runtime error since t1 has already been joined
    if (t1.joinable())
        t1.join(); // This will not execute since t1 is not joinable anymore

    std::cout << "joinFun() after join\n";
}

void detachFun() {
    std::thread t2(run, 10); // Create a thread that runs the function 'run' with argument 10
    std::cout << "detachFun() thread is running\n";
    t2.detach(); // Detach the thread t2, allowing it to run independently

    // t2.detach(); // This will cause a runtime error since t2 has already been detached
    if (t2.joinable())
        t2.detach(); // This will not execute since t2 is not joinable anymore

    std::cout << "detachFun() after detach\n";
}

int main(){
    joinFun(); // Call the function that demonstrates joining a thread
    detachFun(); // Call the function that demonstrates detaching a thread
    std::cout << "main() thread is running\n";

    return 0; // Return 0 to indicate successful execution of the program
}