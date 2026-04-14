#include <iostream>
#include "header.hpp"

using namespace std;

// class GFG is declared as a friend
// inside class Geeks, therefore
// Class GFG can access private members
// of class Geeks.
class GFG {
public:
    void display(Geeks& t) {
        cout << "The value of Private Variable = "
             << t.private_variable << endl;
        cout << "The value of Protected Variable = "
             << t.protected_variable << endl;
    }
};

int main() {
    Geeks g;
    GFG fri;
    fri.display(g);
    return 0;
}
