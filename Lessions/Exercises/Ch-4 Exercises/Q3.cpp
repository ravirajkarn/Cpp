/*

Exercise 3
Write a C++ program that reads an article number, a quantity, and a unit price
from the keyboard and outputs the data on screen as displayed on the opposite
page.

Screen output for exercise 3
Article Number   Number of Pieces  Price per piece
.......              ......           ...... Dollar 

*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main (){
    string number("Article Number "), piece("Number of Pieces "), price("Price per piece "), Dollar(" Dollar");
    int artical_no(0), no_pieces(0), width = 50;
    double price_per_piece(0);

    cout << number;
    cin >> artical_no;
    cout << endl << piece ;
    cin >> no_pieces;
    cout << endl << price;
    cin >> price_per_piece;

    cout << setw(number.length()) << number << setw(price.length()) << piece << setw(price.length()) << price << endl;
    cout << setw(number.length()/2) << artical_no << setw(number.length()/2 + price.length()/2) << no_pieces << setw(price.length()/2 + price.length()/2) << price_per_piece << Dollar << endl;
    
    return 0;
}