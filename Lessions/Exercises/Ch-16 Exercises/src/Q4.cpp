/**
 * @file Q3.cpp
 * @author Sumit Kumar (ravirajkarn21@gmail.com)
 * @brief
 * @details following banner
 *

            * * * * B R E A K * * * *

--- Press interrupt key to terminate (^C) ---

 * is to be displayed in the center of the window and scrolled left.You can
 * scroll the banner by beginning string output with the first character, then
 * the second, and so on. Handle the string like a loop where the first letter
 * follows the last letter and output continues until the starting position is
 * reached. You can use a wait loop to modify the speed of the banner after each
 * string is output.
 *
 * @version 0.1
 * @date 2025-06-15
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <sys/ioctl.h>
#include <unistd.h>

#include <cstring>
#include <iomanip>
#include <iostream>
#include <print>

//* The code given by the book. I am able to what this code is doing crashes my
//* terminal. So, what I under stand in the given problem is to print the banner
//* that's it. I think in early times it was a huge dell to print but now it's
//* not.

// using namespace std;
// #define DELAY 10000000L

// // Output delay
// inline void cls() { cout << "\033[2J\n"; }
// // Clear screen
// inline void locate(int z, int s)
// // Put cursor in row z
// {
//   // and column s
//   cout << "\033[" << z << ';' << s << 'H';
// }
// char msg[] = "* * * B R E A K * * * ";

// int main() {
//   int i, start = 0, len = strlen(msg);
//   cls();
//   locate(24, 20);
//   // Row 24, column 20
//   cout << "--- Press interrupt key to terminate (^C) ---";
//   while (true) {
//     locate(12, 25);
//     // Row 12, column 25
//     i = start;
//     // Output from index start
//     do {
//       cout << msg[i++];
//       i = i % len;
//       // if( i == len) i = 0;
//     } while (i != start);
//     cout << endl;
//     // Outputs buffer to screen
//     // Wait in short
//     for (int count = 0; count < DELAY; ++count);
//     ++start;
//     // For next output
//     start %= len;
//     // start = start % len;
//   }
//   cls();
//   return 0;
// }

int main() {
  struct winsize w;

  std::string terminateText = "--- Press interrupt key to terminate (^C) ---";
  std::string msg = "* * * B R E A K * * * ";

  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  std::print("{0:^{1}}\n", msg, w.ws_row);
  std::print("{}\n\n", terminateText);
  return 0;
}
