/**
 * @file Q3.cpp
 * @author Sumit Kumar (ravirajkarn+support@outlook.com)
 * @brief Exercise 3
 * Create a program to simulate the signal positions for two sets of traffic lights at
 * a junction. Use the class Lights as defined in this chapter for your program.
 * ■ Each set of lights is switched through the phases red, amber, green, amber,
 * red, and so on.You must ensure that one set of lights can be only in the
 * amber or green state when the other set of lights is red.
 * ~■ The lights operate in an infinite loop that can be terminated by interrupting
 * ~the program.You can use the key combination <Ctrl>+<C> for DOS
 * ~and Windows and the Interrupt key, i.e., normally the <Del> key, for
 * ~UNIX.
 * ■ The status of the lights is constant for a certain number of seconds. For
 * example, the green phase can take 20 seconds and the amber phase 1
 * second.These values can be different for each set of lights. Define an
 * auxiliary function
 ** inline void wait( int sec)
 * The function returns after the stipulated number of seconds.To do so,
 * you can call the standard function time() in a loop. Don’t forget to read
 * the notes on the opposite page.
 * @version 0.1
 * @date 2024-07-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */

 #include <fmt/core.h>
 #include <fmt/color.h>
 #include <fmt/chrono.h>
 #include <thread>

class Traffic_light{
    public:
    void red(){
        fmt::print(fg(fmt::color::red), "Red");
    }
    void amber(){
        fmt::print(fg(fmt::color::orange), "Amber");
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    void green(){
        fmt::print(fg(fmt::color::green), "Green");
        std::this_thread::sleep_for(std::chrono::seconds(20));
    }
    void start(){
            amber();
            green();
            amber();
            red();
    }
};

/* Written by AI */

 class Traffic_Light {
 public:
     enum class State {
         RED,
         AMBER,
         GREEN
     };
 
     Traffic_Light(State initialState = State::RED, int greenDuration = 20, int amberDuration = 1)
         : currentState(initialState), greenDuration(greenDuration), amberDuration(amberDuration) {}
 
     void red() {
         fmt::print(fg(fmt::color::red), "Red");
     }
 
     void amber() {
         fmt::print(fg(fmt::color::orange), "Amber");
         std::this_thread::sleep_for(std::chrono::seconds(amberDuration));
     }
 
     void green() {
         fmt::print(fg(fmt::color::green), "Green");
         std::this_thread::sleep_for(std::chrono::seconds(greenDuration));
     }
 
     void changeState() {
         switch (currentState) {
         case State::RED:
             currentState = State::AMBER;
             break;
         case State::AMBER:
             currentState = State::GREEN;
             break;
         case State::GREEN:
             currentState = State::AMBER;
             break;
         }
     }
 
     void displayState() {
         switch (currentState) {
         case State::RED:
             red();
             break;
         case State::AMBER:
             amber();
             break;
         case State::GREEN:
             green();
             break;
         }
     }
 
     State getState() const { return currentState; }
 
 private:
     State currentState;
     int greenDuration;
     int amberDuration;
 };
 
 // Auxiliary wait function
 inline void wait(int sec) {
     std::this_thread::sleep_for(std::chrono::seconds(sec));
 }
 
 int main() {

    // Written by me
    // Traffic_light tl,t2;
    // while(true){
    // tl.start();
    // fmt::print("\n\t"); 
    // t2.start();
    // fmt::print("\n");
    // }

    // Written by AI

     Traffic_Light tl1(Traffic_Light::State::RED, 20, 1); // Green lasts 20 seconds, Amber lasts 1 second
     Traffic_Light tl2(Traffic_Light::State::RED, 15, 3); // Green lasts 15 seconds, Amber lasts 3 seconds
 
     while (true) {
         // Traffic Light 1
         tl1.displayState();
         tl1.changeState();
 
         fmt::print("\n\t");
 
         // Traffic Light 2 - Ensure it's Red when tl1 is Amber or Green
         if (tl1.getState() == Traffic_Light::State::AMBER || tl1.getState() == Traffic_Light::State::GREEN) {
             tl2.red();
         } else {
             tl2.displayState();
             tl2.changeState();
         }
 
         fmt::print("\n");
 
         // Wait for a short duration to simulate the passage of time
         wait(1);
     }
 
     return 0;
 }