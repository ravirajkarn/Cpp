#include <string>

namespace calculate
{
    // String number addition.
    int add(std::string &num1 , std::string &num2)
    {
        return std::stoi(num1) + std::stoi(num1);
    }

    // String multiplication.
    int multi(std::string &num1 ,std::string &num2)
    {
        return stoi(num1)*stoi(num2);
    }

    // String subtraction (num1 - num2).
    int minus(std::string &num1 , std::string &num2)
    {
        return std::stoi(num1) - std::stoi(num1);
    }
    
    // String division. (num1/num2)
    int division(std::string &num1 , std::string &num2)
    {
        return std::stoi(num1) / std::stoi(num1);
    }
    
} // namespace calculate

namespace strcal
{
    // addition
    std::string add(std::string &num1, std::string &num2)
    {
        
    }
    
    int add(std::string &num1,int start1, int end1 ,std::string &num2, int start2, int end2)
    {
        std::string nu1m(num1,start1,end1) , nu2m(num2, start2, end2);  //* all elements of string should be a number before conversion.
        return stoi(nu1m)+ stoi(nu2m);            //* stoi(string) convert number contain in the string into number.
    }

    // multiplication
    int multi(std::string &num1 , std::string &num2)
    {
        return std::stoi(num1) * std::stoi(num1);
    }

    // subtraction
    int minus(std::string &num1,int start1, int end1 ,std::string &num2, int start2, int end2)
    {
        std::string nu1m(num1,start1,end1) , nu2m(num2, start2, end2);  //* all elements of string should be a number before conversion.
        return stoi(nu1m) - stoi(nu2m);            //* stoi(string) convert number contain in the string into number.
    }

    // division
    int division(std::string &num1,int start1, int end1 ,std::string &num2, int start2, int end2)
    {
        std::string nu1m(num1,start1,end1) , nu2m(num2, start2, end2);  //* all elements of string should be a number before conversion.
        return stoi(nu1m)/stoi(nu2m);            //* stoi(string) convert number contain in the string into number.
    }
} // namespace strcal
