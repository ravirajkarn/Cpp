// #include <iostream>
#include <termios.h>
#include <unistd.h>
#include <stdexcept>
#include "fmt/core.h"


class Terminal {
public:
    Terminal() {
        // Get the current terminal settings
        if (tcgetattr(STDIN_FILENO, &old_settings_) == -1) {
            throw std::runtime_error("Failed to get terminal attributes");
        }

        new_settings_ = old_settings_;
        // Disable canonical mode (line buffering) and echoing
        new_settings_.c_lflag &= ~(ICANON | ECHO);

        // Apply the new settings immediately
        if (tcsetattr(STDIN_FILENO, TCSANOW, &new_settings_) == -1) {
            throw std::runtime_error("Failed to set terminal attributes");
        }
    }

    ~Terminal() {
        // Restore the original terminal settings in the destructor
        tcsetattr(STDIN_FILENO, TCSANOW, &old_settings_);
    }

private:
    struct termios old_settings_;
    struct termios new_settings_;
};

int main() {
    try {
        // Create an instance of our Terminal class
        // The constructor will set the terminal to cbreak mode
        // The destructor will restore it automatically on exit
        Terminal terminal;

        char ch;
        while ((ch = getchar()) != 'q') {
            switch (ch) {
            case 'w':
                fmt::print("UP Key\n");
                break;
            case 's':
                fmt::print("Down Key\n");
                break;
            case 'a':
                fmt::print("Left Key\n");
                break;
            case 'd':
                fmt::print("Right key\n");
                break;
            default:
                fmt::print("{}\n", ch);
                break;
            }
        }
    }
    catch (const std::exception& e) {
        fmt::print("Error: {}\n", e.what());
        return 1;
    }

    return 0;
}

/*

#include <iostream>

#ifdef _WIN32
#include <conio.h>
int get_char_unbuffered() {
    return _getch();
}
#else
#include <termios.h>
#include <unistd.h>
#include <stdexcept>

// Global variables to store and restore terminal settings
static struct termios old_settings;
static bool term_in_raw_mode = false;

// Function to put the terminal in raw mode
void set_terminal_raw() {
    if (term_in_raw_mode) return;

    struct termios new_settings;
    tcgetattr(STDIN_FILENO, &old_settings);
    new_settings = old_settings;

    new_settings.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);

    term_in_raw_mode = true;
}

// Function to restore terminal settings
void restore_terminal() {
    if (term_in_raw_mode) {
        tcsetattr(STDIN_FILENO, TCSANOW, &old_settings);
        term_in_raw_mode = false;
    }
}

// Function to read a single character unbuffered
int get_char_unbuffered() {
    set_terminal_raw();
    return getchar();
}
#endif

int main() {
    std::cout << "Press any key to see its value. Press 'q' to quit." << std::endl;
    std::cout << "This code works on both Linux/macOS and Windows." << std::endl;

    int ch;
    do {
        ch = get_char_unbuffered();
        // Use a standard I/O function to print the output
        std::cout << "You pressed: " << ch << std::endl;
    } while (ch != 'q');

#ifndef _WIN32
    // On POSIX, we need to explicitly restore the terminal mode before exiting.
    // We could use a RAII class here for better safety, as in the previous example.
    restore_terminal();
#endif

    return 0;
}

*/