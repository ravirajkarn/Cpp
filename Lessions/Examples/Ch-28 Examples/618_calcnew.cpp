// calc_new.cpp: New version of function calc(),
// which throws exceptions of type
// MathError.
// ----------------------------------------------------
#include <string>
#include <iostream>
using namespace std;
class MathError
{
private:
    string message;

public:
    MathError(const string &s) : message(s) {}
    const string &getMessage() const { return message; }
};
double calc(int a, int b);
int main()
{
    int x, y;
    bool flag = false;
    do
    {
        try // try block
        {
            cout << "Enter two positive integers: ";
            cin >> x >> y;
            if (cin.fail()) // Check for input failure
            {
                cin.clear();             // Clear the error state
                cin.ignore(10000, '\n'); // Discard invalid input
                cerr << "Invalid input. Please enter integers." << endl;
                continue; // Skip to the next iteration
            }
            cout << x << "/" << y << " = " << calc(x, y) << '\n';
            flag = true; // To leave the loop.
        }
        catch (MathError &err) // catch block
        {
            cerr << err.getMessage() << endl;
        }
        catch (...) // catch all other exceptions
        {
            cerr << "Unknown error occurred." << endl;
            exit(1);
        }
    } while (!flag);
    // continued ...
    return 0;
}
double calc(int a, int b)
{
    if (b < 0)
        throw MathError("Denominator is negative!");
    if (b == 0)
        throw MathError("Division by 0!");
    return ((double)a / b);
}