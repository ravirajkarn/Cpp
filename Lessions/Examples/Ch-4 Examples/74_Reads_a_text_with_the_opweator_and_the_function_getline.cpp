//Reads a text with the operator >> and the function getline().

#include <iostream>
#include<string>

using namespace std;

string header = "   --- Demonstrates Unformatted Input ---";

int main()
{
    string word, rest;
    cout << header 
         << "\n\nPress <return> to go on" << endl;

    cin.get();      //read the new line without saving.

    cout << "\nPlease enter a sentaence with several words!" 
         << "\nEnd with <!> and <return>."
         << endl;
    
    cin >> word ;           //   read the first word
    getline(cin, rest, '!');        // and the remaining test up to the character !

    cout << "\nThe first word:  " << word 
         << "\nRemaining test:  " << rest << endl;
    
    return 0;
}