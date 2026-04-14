/*
~ check wether stoi convert negative number or not.
*/

#include <iostream>
#include <string>


int main()
{
    int integer;
    std::string number = "-145";

    integer = std::stoi(number);

    integer = -45;

    std::cout << '\n' << stoi(number) << std::endl;

    std::string a = "-45",
           b = "+19";
    
    int i = stoi(a) + stoi(b);
    std::cout << '\n' << 45+19 << '\t' << i << std::endl;

    return 0; 
}