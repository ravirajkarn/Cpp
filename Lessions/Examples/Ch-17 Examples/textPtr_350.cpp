// textPtr.cpp
// Using arrays of char and pointers to char
// -----------------------------------------------------
#include <iostream>

using namespace std;

int main(){
    std::cout << "demonstrating arrays of char and pointers to char.\n\n";

    char text[] = "Good morning!",
        name[] = "bill!";
    char* cPtr = "Hello ";  // Let cPtr point
                            // to "Hello ".
    std::cout << cPtr << name << '\n'
              << text << endl;

    cout << "The text \"" << text
         << "\" starts at address " << (void*)text
         << endl;
    cout << text + 6            // What happens now?  
        << endl;

    cPtr = name;            // Let cPtr point to name, i.e. *cPtr
                            // is equivalent to name[0]

    cout << "This is the " << *cPtr << " of " << cPtr << endl;
    
    *cPtr = 'k';
    cout << "Bill can not " << cPtr << "!\n" << endl;
    return 0;
}