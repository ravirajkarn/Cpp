# 30. Substring with Concatenation of All Words

You are given a string `s` and an array of strings `words`. All the strings of `words` are of **the same length**.

A **concatenated string** is a string that exactly contains all the strings of any permutation of `words` concatenated.

* For example, if `words = ["ab","cd","ef"]`, then `"abcdef"`, `"abefcd"`, `"cdabef"`, `"cdefab"`, `"efabcd"`, and `"efcdab"` are all concatenated strings. `"abcdef"` is not a concatenated string because it is not the concatenation of any permutation of `words`.

Return an array of the starting indices of all the concatenated substrings in `s`. You can return the answer in **any order**.

**Example 1:**

**Input:** s = "barfoothefoobarman", words = ["foo","bar"]  
**Output:** [0,9]  
**Explanation:**  
The substring starting at 0 is `"barfoo"`. It is the concatenation of `["bar","foo"]` which is a permutation of `words`.  
The substring starting at 9 is `"foobar"`. It is the concatenation of `["foo","bar"]` which is a permutation of `words`.

**Example 2:**

**Input:** s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]  
**Output:** []  
**Explanation:**  
There is no concatenated substring.

**Example 3:**

**Input:** s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]  
**Output:** [6,9,12]  
**Explanation:**  
The substring starting at 6 is `"foobarthe"`. It is the concatenation of `["foo","bar","the"]`.  
The substring starting at 9 is `"barthefoo"`. It is the concatenation of `["bar","the","foo"]`.  
The substring starting at 12 is `"thefoobar"`. It is the concatenation of `["the","foo","bar"]`.

**Constraints:**

* `1 <= s.length <= 10^4`
* `1 <= words.length <= 5000`
* `1 <= words[i].length <= 30`
* `s` and `words[i]` consist of lowercase English letters.

---
---

# Solution 1

pure based on my thinking.

---

# Solution 2

## Intuition

Using hash sets or maps here seems like a good idea. We could have a set of words, copy it on each search attempt, and as long as we keep finding current words in it, we remove them from the set.  
Another idea is to leverage the fact that all strings in `words` come equally sized, so the word length stays constant.

## Approach

In my approach, we are going to use hash maps because it's a bit easier. We will have a reference map, where it's noted which word and how many times it should be repeated.

The next step is to iterate through `s` as many times as the length of each string in `words` with different word offset. Let me illustrate this with an example.  
Imagine we have a string `"abbarfoofoobarthe"` and words are `["foo", "bar", "the"]`. The length of each word is `3`, so we need 3 iterations. They symbolize the splits we make in the string `s`:

- `abb arf oof oob art he`
- `a bba rfo ofo oba rth e`
- `ab bar foo foo bar the`  
  This way, in the inner cycle, we can iterate with bigger steps and use a sliding window.

The last step is to use a sliding window. Here is how it's going to work:

- We define a hash map to keep track of how many times we have seen each word.
- We define a sliding window size to keep track of how many words from the `words` array we have managed to use in our sliding window so far.
- We assume that the sliding window is valid; as soon as we find any condition that makes it invalid, we deal with it.
- On each iteration, we take a slice of `s` from the current index and check if this word exists in the reference map; if it does not, we clear our window and move on.
- If the candidate word exists in the reference map, we increment the number of occurrences of this word in our `seen` map.
- If we check this amount against the reference, and if it's bigger, we need to shrink our window from the left until the condition is satisfied.
- Naturally, the sliding window will grow to the right, so when its size reaches the size of the `words` array, we have found the correct position, and we record the left side of the window to the result array.

## Complexity

- Time complexity: O(n × length) where `n` is the size of `s` and `length` is the length of each word in `words`.
- Space complexity: O(m × length) where `m` is the size of `words` and `length` is the length of each word in `words`.

## Solution with Comments

```c++
class Solution {
    // This is the reference map.
    std::unordered_map<std::string, unsigned int> map;
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        std::vector<int> result;

        // Length of each word in words.
        unsigned int length = words[0].size();

        // Initializing the reference map.
        map.clear();
        for (const std::string& word : words)
            map[word]++;

        // Iterate for each offset
        // As many times as the number of characters in each word.
        for (unsigned int offset = 0; offset < length; ++offset) {
            // Sliding window size.
            unsigned int size = 0;
            // Sliding window memory.
            std::unordered_map<std::string, unsigned int> seen;

            // Iterate over the string, with the step equals to length.
            for (unsigned int i = offset; i + length <= s.size(); i += length) {
                // This is the word we're going to check.
                std::string sub = s.substr(i, length);

                // If the word is absent in the reference map,
                // we clear the sliding window and move on.
                auto itr = map.find(sub);
                if (itr == map.end()) {
                    seen.clear();
                    size = 0;
                    continue;
                }

                // Increase the number of occurrences
                // of the word in seen map.
                ++seen[sub];
                ++size;

                // To make sure the sliding window is valid,
                // we need to check only the recent occurrence
                // against the reference,
                // because previous occurrences
                // were checked on previous iterations.
                while (seen[sub] > itr->second) {
                    // If the occurrences amount exceeds
                    // the reference amount,
                    // we shrink the window from the left until
                    // the window becomes valid again.

                    // A word at the beginning of the current sliding window.
                    std::string first = s.substr(i - (size - 1) * length, length);

                    // Remove the occurrence from the window,
                    // shrinking it from the left.
                    --seen[first];
                    --size;
                }
                
                // If we used all words from the words array,
                // we have found the correct spot
                // and we need to calculate the beginning
                // index of the current sliding window.
                if (size == words.size())
                    result.push_back(i - (size - 1) * length);
            }
        }

        return result;
    }
};
```