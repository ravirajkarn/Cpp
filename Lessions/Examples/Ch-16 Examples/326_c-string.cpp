// C-string.cpp  :  Using C strings.
// -----------------------------------------------------
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
char header[] = "\n    ***  C Strings  ***\n\n";
int main()
{
    char hello[30] = "Hello ", name[20], message[80];
    cout << header << "Your first name: ";
    cin >> setw(20) >> name; // Enter a word.
    strcat(hello, name);     // Append the name.
    cout << hello << endl;
    cin.sync(); // No previous input.    //! this doesn't work in my case.
    cout << "\nWhat is the message for today?"
         << endl;
    cin.getline(message, 80); // Enter a line with a
    // max of 79 characters.
    if (strlen(message) > 0) // If string length is
    {                        // longer than 0.
        for (int i = 0; message[i] != '\0'; ++i)
            cout << message[i] << ' '; // Output with
        cout << endl;                  // white spaces.
    }
    return 0;
}