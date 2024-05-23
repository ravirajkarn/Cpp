/*
Exercise 1

Write a C++ program to
    ■   initialize a string s1 with the string "As time by ..." and a second
        string s2 with the string "goes",
    ■   insert string s2 in front of "by" in string s1,
    ■   erase the remainder of string s1 after the substring "by",
    ■   replace the substring "time" in s1 with "Bill".

In each case, your program should determine the position of the substring.
    Output string s1 on screen at the beginning of the program and after every
modification.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main(){
    //~ initialize a string s1 with the string "As time by ..." and a second string s2 with the string "goes".
    string s1("As time by ..."), s2("goes"), fd_word , er_word;
    
    //~ insert string s2 in front of "by" in string s1.
    cout << s1 << "\nType the word where you want to insert \" "<< s2 << " \" infront of your chosen word.\n";
    getline(cin,fd_word);
    s1.insert(s1.find(fd_word),s2);
    cout << s1 << endl;

    //~ erase the remainder of string s1 after the substring "by".
    cout << endl << "write the word which you want to rease" << endl;
    getline(cin,er_word);
    s1.erase(s1.find(er_word), s1.find(er_word)+er_word.length());
    cout << s1 << endl;

    //~ ■   replace the substring "time" in s1 with "Bill"
    string repl_word, word_to_replace;
    cout << "write word you want to replace: ";
    getline(cin,word_to_replace);
    cout << "write word you want to replace with: ";
    getline(cin, repl_word);
    s1.replace(s1.find(word_to_replace), word_to_replace.length(),repl_word);
    cout << s1 << endl;

    return 0;       
}