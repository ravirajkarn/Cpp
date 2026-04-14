#include <iostream>
#include <vector>
#include <string>

int main(){
    std::vector<std::string> v0 = {"hello", "test", "of", "range", "based", "loop", "to", "access", "the", "previous", "element"};
    for (auto& temp : v0)
    {
        // auto steps = *(&temp + 1);
        std::cout << temp << " " << steps;
    }
    return 0;   
}