#include <iostream>
#include <string>
#include <vector>

class Inversion
{
private:
    std::string input_str;
    int no_of_inversion = 0;
public:
    Inversion(std::string input);
    void inversion(std::string str, unsigned int position1, unsigned int position2);
    int investigate_question_mark(std::vector<std::string> &all_possible_set);
    ~Inversion();
};

Inversion::Inversion(std::string input) : input_str(input)
{
    // find the number of question marks.
    unsigned int question_marks = 0;
    for(const auto &temp : input)
    if (temp == '?')
    question_marks++;

    // replacing '?' from the strMing.
    std::vector<std::string> vec;
    vec.push_back(this->input_str);
    for (int i = this->investigate_question_mark(vec); i != -1; i = this->investigate_question_mark(vec))
    {
        // function will replace the last character '?' with 0 or 1.
        std::string temp = vec.at(i);
        auto position = temp.rfind('?');
        if (position != std::string::npos)
        {
            temp.at(position) = '0'; 
            vec.push_back(temp);
            temp.at(position) = '1'; 
            vec.push_back(temp);
            vec.erase(vec.begin() + i);
        }
    }
}

/**
 * @brief function will determine whether all the elements of the given vector contain '?' or not.
 * 
 * @param all_possible_set 
 * @return int element position which contain the ?.
 * @return -1 if non the element contain ?.
 */
int Inversion::investigate_question_mark(std::vector<std::string> &all_possible_set)
{
    for (unsigned int i = 0; i < all_possible_set.size(); i++)
    {
        std::string temp = all_possible_set.at(i);
        for (const auto temp2 : temp)
        {
            if(temp2 == '?')
            return i;
        }
    }
    return -1;
}

/**
 * @brief function will inversion the position two character in the string.
 * 
 * @param str The string in which you want the change.
 * @param position1 Position of the first character. @var postion1+1.
 * @param position2 Position of the second character. @var postion1+1.
 */
void Inversion::inversion(std::string str, unsigned int position1, unsigned int position2)
{
    auto temp = str[position1];
    str[position1] = str[position2];
    str[position2] = temp;
}

Inversion::~Inversion()
{
}


int main(){
    std::string input_string("1?3?");

    Inversion firs(input_string);
    
    return 0;    
}