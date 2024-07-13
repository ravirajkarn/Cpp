//Enter a character and outputs its octal, decimal, and hexadecimal code.

#include <iostream>             //Declaration of cin, cout 
#include <iomanip>              //For manipulators being call with arguments.

#include <string>
using namespace std;

int main()
{
    int number = ' ';
     
    cout << "The white space code is as follows: "
         << number << endl;
    char ch;
    string prompt = "\nPlease enter a character followed by <return>: ";
    cout << prompt;

     //getline(cin,);
    cin >> ch   ;            // Read a character 
    number = ch ;

    cout << uppercase       // Fpr hex-digits 
         << "   octal decimal hexadecimal\n "
         << oct << setw(8) << number 
         << dec << setw(8) << number 
         << hex << setw(8) << number << endl;
    cin >> ch ;
    return 0; 
}