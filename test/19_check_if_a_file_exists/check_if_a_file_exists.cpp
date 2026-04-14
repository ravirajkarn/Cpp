#include <iostream>
// #include <iomanip>
#include <filesystem>

int main(){
    std::string fileName = "./mango.txt";
    // since ISO C++17:
    std::cout <<std::boolalpha <<"\n" << std::filesystem::exists(fileName) << std::endl;

    // boost:
    // boost::filesystem::exists(fileName)
    
    return 0;
}