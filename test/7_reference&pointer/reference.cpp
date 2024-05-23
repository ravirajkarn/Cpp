//This Program is to understand and learn the concept of reference.cpp

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    double a = 10.4 , & b = a, *c;

    cout << a << "\t" << &a << endl; 
    cout << b << "\t" << &b << endl;
    cout << &c << "\t" << c << "\t" << *c << "\n\n\n"; 

    c = &b;
    cout << &c << "\t" << c << "\t" << *c << "\n\n\n";

    c=&a;
    cout << &c << "\t" << c << "\t" << *c << "\n\n\n";

    //c=NULL;
    //cout << &c << "\t" << c << "\t" << *c << "\n\n\n";

    return 0;
}