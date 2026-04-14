#include <iostream>
#include <string>

using namespace std;

int main(){
    string a[4];
    a[0] = "I hane learned something new again!", a[2]=" * ";
    cout << "string \"" << a[0] << "\" contain " << a[0].length() << " character. \n";
    cout << "enter first line: ";
    getline(cin,a[1]);
    cout << "enter second line: ";
    getline(cin,a[3]);
    cout << "new string with * :: " << a[1]+a[2]+a[3];
    return 0;
}