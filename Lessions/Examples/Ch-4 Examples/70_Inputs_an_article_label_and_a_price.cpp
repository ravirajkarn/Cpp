//Inputs an article label and a price.

#include <iostream>     
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    string lable;
    double price;

    cout << "\nPlease enter an article label: ";
    // Input the label (15 charactes maximum):
    cin >> setw(16);        //or:   cin.width(16);
    cin >> lable;

    cin.sync() ; //Clears the buffer resets
    cin.clear() ;  //any error flags that may be set

    cout << "\nEnter the price of the article: ";
    cin >> price;       //Input the price 

    //Controlling output:
    cout << fixed << setprecision(2) << "\nArticle:"
         << "\n Label : " << lable
         << "\n Price : " << price << endl;
    return 0;
}