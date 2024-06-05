#include <string>
#include <iostream>
#include <set> //! define set

// using namespace std;

// string calculating
namespace str_cal
{
    // addition (num1 + num2)
    int add(std::string num1 = "0", std::string num2 = "0")
    {
        return (std::stoi(num1) + std::stoi(num2));
    }

    // subtraction (num1 - num2)
    int sub(std::string num1 = "0", std::string num2 = "0")
    {
        return (std::stoi(num1) - std::stoi(num2));
    }

    // multiplication (num1 * num2)
    int multi(std::string num1 = "1", std::string num2 = "1")
    {
        return (std::stoi(num1) * std::stoi(num2));
    }
} // namespace str_cal

// Removing space in the equation.
void spac_rem(std::string &equation)
{
    while (equation.find(' ') != std::string::npos) // identify the character ' ' int the equation string.
    {
        int a = equation.find(' ');
        equation.erase(a, 1); // remove the character ' ' from equation.
    }
}

// number of blocks in the equation.
int no_of_blocks(std::string &equation)
{
    int blocks(1);
    for (int i = 0; i < equation.size(); i++)
    {
        switch (equation.at(i))
        {
        case '+':
            blocks++;
            break;
        case '-':
            blocks++;
            break;
        case '=':
            if (equation.at(i + 1) != '-')
                blocks++;
            break;
        default:
            break;
        }
    }
    return blocks;
}

// sign reversing after = sign
bool reverse(std::string &equation, bool state = false)
{
    if (state == true)
    {
        switch (equation[0])
        {
        case '+':
            equation.erase(0, 1);
            equation.insert(0, "-");
            break;
        case '-':
            equation.erase(0, 1);
            equation.insert(0, "+");
            break;
        default:
            equation.insert(0, "-");
            break;
        }
    }
    return state;
}

// cut single block out of equation
std::string blocks(std::string &equation)
{
    bool sign_reverse = false;
    int initial(0), count(0);
    switch (equation.at(0))
    {
    case '+':
        count++;
        break;
    case '-':
        count++;
        break;
    case '=':
        initial = 1;
        sign_reverse = true;
        break;
    default:
        break;
    }
    for (count = count + initial; equation[initial + count] != '+' && equation[initial + count] != '-' && equation[initial + count] != '=' && (count + initial) < equation.size(); count++)
        ;
    std::string result(equation, initial, count);
    equation.erase(initial, count);

    reverse(result, sign_reverse);

    return result;
}

// variable identification

/*my version
char variable_identify(std::string equation)
{
    std::string variables;
    for (int i = 0; i < equation.size(); i++)
    {
        bool check = isalpha(equation[i]);
        if (check == true)
        {
            bool match = false;

            for (int n = 0; n < variables.size(); n++)
                if (variables[n] == equation[i])
                    match = true;

            if (match == false)
                variables = variables + equation[i] + " ";
        }
    }

    std::cout << '\n'
              << variables.size() << '\n';

    if (variables.size() == 2)
    {
        return variables[0];
    }
    else
    {
        std::cout << "choose a variable: " << variables << std::endl;
        char variable1;

        while (std::cin >> variable1)
        {
            for (int i = 0; i < variables.size(); i++)
            {
                if (variable1 == variables[i])
                {
                    return variables[i];
                    break;
                }
            }
            std::cout << "variable not match. \n";
        }
    }
    return 'x';
} */
// improved by AI
char variable_identify(const std::string &inputEquation)
{
    std::set<char> uniqueVariables; //! std::set ensures that only unique variables are stored, so duplicates are automatically handled.

    for (char ch : inputEquation) //! Range-Based Loop (for (char ch : inputEquation)):
    {                             //! This loop iterates over each character (ch) in the inputEquation string
        if (std::isalpha(ch))
        {
            uniqueVariables.insert(ch);
        }
    }

    if (uniqueVariables.size() == 1)
    {                                    //! .begin() define in set header file. It give the pointer to the first value.
        return *uniqueVariables.begin(); // Return the first variable
    }
    else
    {
        std::cout << "Choose a variable: ";
        for (char var : uniqueVariables)
        {
            std::cout << var << ' ';
        }
        std::cout << '\n';

        char chosenVariable;
        while (std::cin >> chosenVariable)
        {
            if (uniqueVariables.count(chosenVariable))
            {
                return chosenVariable;
            }
            else
            {
                std::cout << "Variable not found. Try again: ";
            }
        }
    }

    return 'x'; // Default fallback
}

// same variable
std::string same_power(std::string equation, char variable = '\0', int power = 0)
{
    // Validate input
    if (equation.empty() || !isalpha(variable))
        return "same_power: variable or equation is empty.";

    // finding the position of the variable.
    size_t found_it = equation.find(variable); //! size_t is same as unsigned int. difference is int is 32bit based,
                                               //! where size_t is adaptive based on system 32 or 64.

    if (equation[found_it + 1] == '^')
        if (std::stoi(equation.substr(found_it + 2)) == power) //! equation.substr(initial, count) copy the string from the equation and output it.
            return equation;
        else
            return "";
    else if (equation[found_it + 1] == '\0' && power == 1)
        return equation;
    else if (found_it == std::string::npos && power == 0)
    {
        return equation;
    }
    return "";
}

// remove variable and return the number
long double remover(std::string equation, char variable)
{
    // validating the equation
    if (equation.empty())
        return 0;

    // return the number.
    size_t found_it = equation.find(variable);
    if (found_it != std::string::npos)
    {
        std::string result = equation.substr(0, found_it);
        if (result.size() == 1)
        {
            if (result[0] == '-')
                return -1;
            else if (result[0] == '+')
                return 1;
            else
                return std::stold(result);
        }
        else if (result.empty())
            return 1;
        else
            return std::stold(result);
    }
    else
        return std::stold(equation);
}

// grouping and giving the value a, b, c;
void grouping(std::string equation, long double &a, long double &b, long double &c)
{
    spac_rem(equation);

    int no_blocks = no_of_blocks(equation);

    std::string terms[no_blocks];

    char variable = variable_identify(equation);

    for (int i = 0; i <= no_blocks; i++)
    {
        terms[i] = blocks(equation);
    }

    // power 2 return a
    for (int i = 0; i < no_blocks; i++)
    {
        a = a + remover(same_power(terms[i], variable, 2), variable);
    }

    // power 1 return b
    for (int i = 0; i < no_blocks; i++)
    {
        b = b + remover(same_power(terms[i], variable, 1), variable);
    }

    // power 0 return c
    for (int i = 0; i < no_blocks; i++)
    {
        c = c + remover(same_power(terms[i], variable, 0), variable);
    }
}
