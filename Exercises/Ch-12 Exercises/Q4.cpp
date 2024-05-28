// Exercise 4
// Create a function quadEquation() that calculates the solutions to quadratic
// equations.The formula for calculating quadratic equations is shown opposite.
// Arguments: The coefficients a, b, c and two pointers to both solutions.
// Returns: false, if no real solution is available, otherwise true.
// Test the function by outputting the quadratic equations on the opposite page
// and their solutions.

#include <iostream>
#include <string>

// Removing space in the equation.
void era_eq( std::string &equation)
{
    while (equation.find(' ') != std::string::npos) // identify the character ' ' int the equation string.
    {
        int a = equation.find(' ');
        equation.erase(a,1);                        // remove the character ' ' from equation.
    }
}

// cutting out a block from equation.
std::string block(std::string &equation)
{
    // int position = 0, count = 0;
    // switch (equation.at(0))
    // {
    // case '+':
    //     position = 0; count = 1;
    //     break;
    // case '-':
    //     position = 0, count = 1;
    //     break;
    // case '=':
    //     position = 1, count = 1;
    //     break;
    // default:
    //     position = 0, count = 0;
    //     break;
    // }

    // for (; equation[count] != '+' && equation[count] != '-' && equation[count] != '=' && count < equation.size(); count++ )
    //         ; // finding the length of a block.

    //     std::string result(equation, position, count); // creating a temp block.
    //     equation.erase(0, count);               // erasing result from the equation.
    //     return result;                      // output block

    if (equation.at(0) == '(')
    {
        int count(0);
        for (; equation[count] != '+' && equation[count] != '-' && equation[count] != '=' && equation[count] != ')' && count < equation.size(); count++)
        {
            std::string result(equation, 0, count); // creating a temp block.
            equation.erase(0, count);               // erasing result from the equation.
            if (equation[count] == ')' && equation[count+1] == '(')
                result = result + block(equation);
            return result;
        }   
    }
}

int main(){
    std::string //a ("245x^2+79x+45=0"),
                //b ("245x^2+79x+45=4455");
                c ("(45+79)(x^2)+45x=0"),
                d ("459(x^2)+85x+45=0");

    era_eq(c); // removing space 
    std::cout << block(c);

    return 0;
}