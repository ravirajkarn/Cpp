#include <iostream>
#include <cmath>
#include <iomanip>
#include "Q4_v2.0_solver.cpp"

using namespace std;

int main()
{
    std::string input;
    long double a(0), b(0), c(0);

    std::cout << setw(20) << "Quadratic equation solver\n"
              << "NOte: NO brackets are allowed." << "\nEnter your equation: ";
    getline(cin, input);

    char variable = variable_identify(input);

    grouping(input, a, b, c);

    long double D = (b * b - 4 * a * c);
    if (D < 0)
    {
        std::cout << "\nNo real solution.\n";
        return '\0';
    }
    else
    {
        long double solution1(0), solution2(0);
        solution1 = (-b + std::sqrt(D)) / (2 * a);
        solution2 = (-b - std::sqrt(D)) / (2 * a);

        std::cout << '\n'
                  << a << variable << "^2 " << showpos << b << variable << " " << c << " = 0 :   "
                  << noshowpos << variable << " = " << setprecision(3) << solution1 << " & " << solution2 << '\n';
    }

    return 0;
}

/*
 Only fail to solve the equation which are in brackets.
 Soon I will fix the issue.
*/