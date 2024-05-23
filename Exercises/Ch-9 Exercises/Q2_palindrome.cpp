/*
Exercise 2

Write a C++ program that reads a word from the keyboard, stores it in a string,
and checks whether the word is a palindrome.A palindrome reads the same
from left to right as from right to left.The following are examples of
palindromes:“OTTO, ” “deed, ” and “level.”
    Use the subscript operator []. Modify the program to continually read and
check words.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main(){
    string input;
    int i, difference;
    bool palindrome(true);

    cout << "\n This Program will check your input wether it is palindrome or not. \n";
    cin >> input;

    i = input.length();
    difference = (i%2==0)? 0 : 1 ;

    for (int b (0); i-b >= difference ; b++, i--)
    {
        palindrome = (input.at(i-1) != input.at(b)) ? false : true;
        if(palindrome == false)
        break;
    }

    if(palindrome == true ){
        cout << input << " is palindrome.";
    }
    else{
        cout << input << " is not a palindrome.";
    }
    
    return 0;    
}