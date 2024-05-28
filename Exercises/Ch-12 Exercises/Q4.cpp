// Exercise 4
// Create a function quadEquation() that calculates the solutions to quadratic
// equations.The formula for calculating quadratic equations is shown opposite.
// Arguments: The coefficients a, b, c and two pointers to both solutions.
// Returns: false, if no real solution is available, otherwise true.
// Test the function by outputting the quadratic equations on the opposite page
// and their solutions.

#include <iostream>
#include <string>
#include <algorithm>
#include "maths.cpp"

// Removing space in the equation.
void era_eq(std::string &equation)
{
    while (equation.find(' ') != std::string::npos) // identify the character ' ' int the equation string.
    {
        int a = equation.find(' ');
        equation.erase(a, 1); // remove the character ' ' from equation.
    }
}

// cutting out block from equation.
std::string block(std::string &equation)
{
    int position = 0, count = 0, b_count(0);
    switch (equation.at(0))
    {
    case '+':
        position = 0;
        count = 1;
        break;
    case '-':
        position = 0, count = 1;
        break;
    case '=':
        position = 1, count = 1;
        break;
    default:
        position = 0, count = 0;
        break;
    }

    for (int b_count = 0; count < equation.size(); count++) // finding the length of a block.
    {
        if (equation[count] == '(')
            b_count++;
        if (equation[count] == ')')
            b_count--;
        if (b_count == 0 && (equation[count] == '+' || equation[count] == '-' || equation[count] == '='))
            break;
    }

    std::string result(equation, position, count); // creating a temp block.
    equation.erase(0, count);                      // erasing result from the equation.
    return result;                                 // output block
}

// solving bracket equation.
std::string bracket(std::string &equation)
{
    int total_bracket_in_equation(0); // no of brackets
    int max_column_in_equation(0); // no of column
    bool row_hits = true;

    // count number of column & bracket in equation.
    for (int i = 0; i < total_bracket_in_equation + 1; i++)
    {
        int column(0);
        for (int n = 0, brack_et(0); n < equation.size(); n++)
        {
            if (i == 0 && equation[n] == '(')
                total_bracket_in_equation++;

            switch (equation[n])
            {
            case '(':
                brack_et++;
                row_hits = true;
                break;
            case ')':
                brack_et--;
                row_hits = true;
            case '+':
                row_hits = true;
                break;
            case '-':
                row_hits = true;
                break;
            default:
                break;
            }
            if (brack_et == i && row_hits == true && (isdigit(equation[n]) || isalpha(equation[n])))
            {
                column++;
                row_hits = false;
            }
        }
        max_column_in_equation = std::max(max_column_in_equation, column);
    }
 
    std::string ele_2D[total_bracket_in_equation+1][max_column_in_equation];

    // initialization of value.
    for (int bracket_no = 0; bracket_no < total_bracket_in_equation + 1; bracket_no++)  //45(((45+6x)+19)8)
    {
        int column(0);
        for (int initial = 0, check_bracket(0), count(0); initial < equation.size(); initial++)
        {
            switch (equation[initial])
            {
            case '(':
                check_bracket++;
                row_hits = true;
                break;
            case ')':
                check_bracket--;             
                row_hits = true;
            case '+':
                row_hits = true;
                break;
            case '-':
                row_hits = true;
                break;
            default:                // 45(((45+6x)+19)8)
                break;
            }
            if (check_bracket == bracket_no && row_hits == true && (isdigit(equation[initial]) || isalpha(equation[initial])|| equation[initial] == '+' || equation[initial] == '-'))  // This will insure I will get i bracket's value.
            {
                // n is inital value
                // final value
                for (count = 1; (count + initial) < equation.size(); count++)
                {
                    if ((isdigit(equation[(count + initial) - 1]) == true || isalpha(equation[(count + initial) - 1])) && equation[(count + initial)] == '(')
                        break;

                    if ((isdigit(equation[(count + initial) - 1]) == true || isalpha(equation[(count + initial) - 1])) && equation[(count + initial)] == ')')
                        break;

                    if (equation[(count + initial)] == '+' || equation[(bracket_no + initial)] == '-')
                        break;
            
                    if (equation[(count + initial)] == '(')
                        check_bracket++;

                    if (equation[(count + initial)] == ')')
                        check_bracket--;
                }    //45(((45+6x)+19)8)

                std::string result(equation,initial,count);
                ele_2D[bracket_no][column] = result ;
                column++;
                row_hits = false;
            }
        }
    }

    equation.erase();

    // calculating the bracket
    std::string result;
    for (int row = (total_bracket_in_equation - 1); row >=0 ; row--)
    {
        for (int column = 0; column < max_column_in_equation; column++)
        {
            switch (ele_2D[row][column].at(0))
            {
            case '+':
                for (int last_column = 0; last_column < max_column_in_equation; last_column++)
                {
                    result = strcal::add(ele_2D[total_bracket_in_equation][last_column],ele_2D[row][column]);
                }                
                break;
            case '-':
                break;
            default:
                break;
            }
        }
        
        
    }
    

    return equation;
}

int main()
{
    std::string a("245x^2+79x+45=0"),
        b("245x^2+79x+45=4455"),
        c("(45+79)(x^2)+45x=0"),
        d("459(x^2)+85x+45=0"),
        e("45(((45+6x)+19)8)"),
        f("245x+(4x+2)+5=0");

    era_eq(a); // removing space
    // std::cout << "\n"/* << block(e)*/ << "\n" << e.length() << "\n";

    bracket(e);

    return 0;
}