#include <fmt/core.h>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <chrono>

/**
 * @brief It check wether the input stand on the given criteria.
 * 
 * @param sentence single sentence from which we going to find concatenation position.
 * @param b cluster of words.
 * @return true if it meet the given condition.
 * @return false(0) if it do not meet the given condition.
 */
inline bool condition_meet(std::string &sentence, std::vector<std::string> &b){
    if (sentence.size() < 1 || sentence.size() > 10000) return false;  // 1 <= sentence.length <= 10^4
    if (b.size() < 0 || b.size() > 5000) return false;   // 1 <= words.length <= 5000
    for (const auto& temp : b){
        if (temp.size() < 1 || temp.size() > 30) return false; // 1 <= words[i].length <= 30
        for (auto alphabet : temp) if(!std::islower(alphabet)) return false; // s and words[i] consist of lowercase English letters
    }
    for (const auto& temp : sentence)
    if(!std::islower(temp)) return false; // s and words[i] consist of lowercase English letters 

    return true;
}

/**
 * @brief creating the concatenation of all words.
 * 
 * @param words list of words. 
 * @return std::vector<std::string> all the permutation of the words.
 */
std::vector<std::string> concatenation(std::vector<std::string> &words){
    
    std::sort(words.begin(), words.end()); // sort the element befor creating permutation.
    std::vector<std::string> result; // storage area where permuted elements will store. 
    std::ostringstream element; // elements of words.
    
    do
    {
        element.str(""); // creating new buffer
        element.clear(); // clearing any error
        
        for(const auto& temp : words)
            element << temp ;

        result.push_back(element.str()); // pushing an elements to the string.

    } while (std::next_permutation(words.begin(), words.end())); // generating permutation
    
    return result;
}

/**
 * @brief return the position of concatenation word in the string.
 * 
 * @param s the string in which we need to find the words.
 * @param element element which we need to find. 
 * @param _position position from where we need to find the word.
 * @return std::vector<int> all the position of the element in string.
 */
std::vector<int> position(std::string& s, std::string& element, int _position = 0 ){
    std::vector<int> positions;

    _position = s.find(element,_position);
    // positions.push_back(_position);
    if ( _position < 0) return positions;
    positions.push_back(_position);
    auto result = position( s, element, _position+1);
    positions.insert(positions.end(), result.begin(), result.end());
    
    return positions;    
}


/*
 * error: empty vector
 */
std::vector<int> concatenation_position(std::string &s, std::vector<std::string> &words){
    if(!condition_meet(s, words)) return std::vector<int>(); // error.

    std::vector<int> result;

    auto concatenated_words = concatenation(words);

    for (auto &single_concatenation_word : concatenated_words)
    {
        auto single_position = position(s, single_concatenation_word);
        result.insert(result.end(), single_position.begin(), single_position.end());
    }  

    return result;
}

class Solution {
public:
    std::vector<int> findSubstring(std::string &s, std::vector<std::string> &words) {
        return concatenation_position(s, words);
    }
};


int main()
{
    fmt::print("hello\n");
    std::string s = "pjzkrkevzztxductzzxmxsvwjkxpvukmfjywwetvfnujhweiybwvvsrfequzkhossmootkmyxgjgfordrpapjuunmqnxxdrqrfgkrsjqbszgiqlcfnrpjlcwdrvbumtotzylshdvccdmsqoadfrpsvnwpizlwszrtyclhgilklydbmfhuywotjmktnwrfvizvnmfvvqfiokkdprznnnjycttprkxpuykhmpchiksyucbmtabiqkisgbhxngmhezrrqvayfsxauampdpxtafniiwfvdufhtwajrbkxtjzqjnfocdhekumttuqwovfjrgulhekcpjszyynadxhnttgmnxkduqmmyhzfnjhducesctufqbumxbamalqudeibljgbspeotkgvddcwgxidaiqcvgwykhbysjzlzfbupkqunuqtraxrlptivshhbihtsigtpipguhbhctcvubnhqipncyxfjebdnjyetnlnvmuxhzsdahkrscewabejifmxombiamxvauuitoltyymsarqcuuoezcbqpdaprxmsrickwpgwpsoplhugbikbkotzrtqkscekkgwjycfnvwfgdzogjzjvpcvixnsqsxacfwndzvrwrycwxrcismdhqapoojegggkocyrdtkzmiekhxoppctytvphjynrhtcvxcobxbcjjivtfjiwmduhzjokkbctweqtigwfhzorjlkpuuliaipbtfldinyetoybvugevwvhhhweejogrghllsouipabfafcxnhukcbtmxzshoyyufjhzadhrelweszbfgwpkzlwxkogyogutscvuhcllphshivnoteztpxsaoaacgxyaztuixhunrowzljqfqrahosheukhahhbiaxqzfmmwcjxountkevsvpbzjnilwpoermxrtlfroqoclexxisrdhvfsindffslyekrzwzqkpeocilatftymodgztjgybtyheqgcpwogdcjlnlesefgvimwbxcbzvaibspdjnrpqtyeilkcspknyylbwndvkffmzuriilxagyerjptbgeqgebiaqnvdubrtxibhvakcyotkfonmseszhczapxdlauexehhaireihxsplgdgmxfvaevrbadbwjbdrkfbbjjkgcztkcbwagtcnrtqryuqixtzhaakjlurnumzyovawrcjiwabuwretmdamfkxrgqgcdgbrdbnugzecbgyxxdqmisaqcyjkqrntxqmdrczxbebemcblftxplafnyoxqimkhcykwamvdsxjezkpgdpvopddptdfbprjustquhlazkjfluxrzopqdstulybnqvyknrchbphcarknnhhovweaqawdyxsqsqahkepluypwrzjegqtdoxfgzdkydeoxvrfhxusrujnmjzqrrlxglcmkiykldbiasnhrjbjekystzilrwkzhontwmehrfsrzfaqrbbxncphbzuuxeteshyrveamjsfiaharkcqxefghgceeixkdgkuboupxnwhnfigpkwnqdvzlydpidcljmflbccarbiegsmweklwngvygbqpescpeichmfidgsjmkvkofvkuehsmkkbocgejoiqcnafvuokelwuqsgkyoekaroptuvekfvmtxtqshcwsztkrzwrpabqrrhnlerxjojemcxel";
    std::vector<std::string> words = {"dhvf","sind","ffsl","yekr","zwzq","kpeo","cila","tfty","modg","ztjg","ybty","heqg","cpwo","gdcj","lnle","sefg","vimw","bxcb"};
    
    auto start = std::chrono::high_resolution_clock::now();
    fmt::print("[");
    auto positions = concatenation_position(s, words);
    for (int i = 0; i < positions.size(); i++)
    {
        fmt::print("{}", positions.at(i));
        if (i!= positions.size() - 1) fmt::print(", ");
    }
    fmt::print("]");
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    fmt::print("\nTime taken: {} microseconds\n", duration.count());

    return 0;
}           