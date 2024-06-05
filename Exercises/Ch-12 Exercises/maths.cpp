#include <string>
#include <algorithm>
#include <iostream>

namespace calculate
{
    // String number addition.
    int add(std::string &num1 , std::string &num2)
    {
        return (std::stoi(num1)+std::stoi(num2));
    }

    // String multiplication.
    int multi(std::string &num1 ,std::string &num2)
    {
        return std::stoi(num1) * std::stoi(num2);
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
    // addition (num1 + num2)
    std::string add(std::string num1, std::string num2)
    {
        bool needstradd = false ; // need string addition?

        // check wether string contain alphabet 
        for (int i = 0; i < std::max(num1.size(), num2.size()) ; i++)
        {
            if (i < num1.size())
            {
                bool test = isalpha(num1[i]);
                if (test == true)
                    needstradd = true;
            }

            if (i < num2.size())
            {
                bool test = isalpha(num2[i]);
                if (test == true)
                    needstradd = true;
            }
        }
        
        if (needstradd == true)
        {
            if (num1.at(0) == '+')
            num1.erase(0,1);
            if (num2.at(0) == '+')
            num2.erase(0,1);
            if (num2.at(0) == '-')
            {
                std::string result = "(" + num1 + num2 + ")";
                return result;
            }
            else
                {
                    std::string result = "(" + num1 + "+" + num2 + ")";
                    return result;
                }
        }
        else
        {
            return (std::to_string(calculate::add(num1, num2)));
        }
    }

    // multiplication

    std::string multi(std::string &num1 , std::string &num2)
    {
        bool needstradd = false ; // need string addition?
        char variable = 'x';

        // check wether string contain alphabet 
        for (int i = 0; i < std::max(num1.size(), num2.size()) ; i++)
        {
            if (i < num1.size())
            {
                bool test = isalpha(num1[i]);
                if (variable != num1[i])
                    std::cout << "\n\t\terror! variable not match.\n";
            }

            if (i < num2.size())
            {
                bool test = isalpha(num2[i]);
                if (variable != num2[i])
                    std::cout << "\n\t\terror! variable not match.\n";
            }
        }

        std::string result = std::to_string(calculate::multi(num1,num2));
        
        
        if (needstradd == true)
        {
            if (num1.at(0) == '+')
            num1.erase(0,1);
            if (num2.at(0) == '+')
            num2.erase(0,1);
            if (num2.at(0) == '-')
            {
                std::string result = "(" + num1 + num2 + ")";
                return result;
            }
            else
                {
                    std::string result = "(" + num1 + "+" + num2 + ")";
                    return result;
                }
        }
        else
        {
            return (std::to_string(calculate::add(num1, num2)));
        }
    }

    // subtraction(num1 - num2)
    std::string minus(std::string num1, std::string num2)
    {
        bool needstradd = false ; // need string addition?

        // check wether string contain alphabet 
        for (int i = 0; i < std::max(num1.size(), num2.size()) ; i++)
        {
            if (i < num1.size())
            {
                bool test = isalpha(num1[i]);
                if (test == true)
                    needstradd = true;
            }
            if (i < num2.size())
            {
                bool test = isalpha(num2[i]);
                if (test == true)
                    needstradd = true;
            }
        }
        
        if (needstradd == true)
        {
            if (num1.at(0) == '+')
            num1.erase(0,1);
            if (num2.at(0) == '+')
            num2.erase(0,1);
            if (num2.at(0) == '-')
            {
                std::string result = "(" + num1 + num2 + ")";
                return result;
            }
            else
                {
                    std::string result = "(" + num1 + "-" + num2 + ")";
                    return result;
                }
        }
        else
        {
            return (std::to_string(calculate::minus(num1, num2)));
        }
    }

    // division
    int division(std::string &num1,int start1, int end1 ,std::string &num2, int start2, int end2)
    {
        std::string nu1m(num1,start1,end1) , nu2m(num2, start2, end2);  //* all elements of string should be a number before conversion.
        return stoi(nu1m)/stoi(nu2m);            //* stoi(string) convert number contain in the string into number.
    }
} // namespace strcal
