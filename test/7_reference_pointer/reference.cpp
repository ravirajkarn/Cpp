//This Program is to understand and learn the concept of reference.cpp

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    double a = 10.4 , & b = a, *c;
    std::cout << '\n';
    cout << a << "\t" << &a /*<<'\t'<< *a */<< endl; 
    cout << b << "\t" << &b << endl;

    cout << &c << "\t" << c << "\t" ; 
    cout << *c << "\n\n\n"; 

    c = &b;
    cout << &c << "\t" << c << "\t" << *c << "\n\n\n";

    /*c = b;
    cout << &c << "\t" << c << "\t" << *c << "\n\n\n";
    */
    
    c=&a;
    cout << &c << "\t" << c << "\t" << *c << "\n\n\n";

    c=NULL;
    cout << &c << "\t" << c << "\t" /*<< *c*/ << "\n\n\n";

    return 0;
}

/**
 * Summery:
 * 1. Reference is an alias to the variable. like my name is sumit and I am also called as ravirajkarn, so ravirajkarn is my reference.
 ** 2. Reference is a constant pointer, which means it can not be changed to point to another variable.
 *
 ** 1. Pointer is a variable which stores the address of another variable. It is like a person who knows everything about me, but he is not me.
 ** 2. Pointer can be changed to point to another variable.
 * 
 */