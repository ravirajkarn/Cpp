/**
 * @file Q3.cpp
 * @author Sumit Kumar (ravirajkarn+support.com)
 * @brief Exercise 3
 * Create a program to simulate the signal positions for two sets of traffic lights at
 * a junction. Use the class Lights as defined in this chapter for your program.
 * ■ Each set of lights is switched through the phases red, amber, green, amber,
 * red, and so on.You must ensure that one set of lights can be only in the
 * amber or green state when the other set of lights is red.\
 * ■ The lights operate in an infinite loop that can be terminated by interrupting
 * the program.You can use the key combination <Ctrl>+<C> for DOS
 * and Windows and the Interrupt key, i.e., normally the <Del> key, for
 * UNIX.
 * ■ The status of the lights is constant for a certain number of seconds. For
 * example, the green phase can take 20 seconds and the amber phase 1
 * second.These values can be different for each set of lights. Define an
 * auxiliary function
 * inline void wait( int sec)
 * The function returns after the stipulated number of seconds.To do so,
 * you can call the standard function time() in a loop. Don’t forget to read
 * the notes on the opposite page.
 * @version 0.1
 * @date 2024-07-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */
