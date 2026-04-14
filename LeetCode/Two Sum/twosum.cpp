#include <vector>
#include <unordered_map>

/**
 * @brief it's time complexity is O(n^2) and space complexity is O(1)
 * 
 */
class Solution {
    public:
        std::vector<int> twoSum(std::vector<int>& nums, int target) {
        for (int i1 = 0; i1 < nums.size(); i1++)
        {
            for (int i2 = i1+1 ; i2 < nums.size(); i2++)
            {
                if (nums.at(i1) + nums.at(i2) == target)
                {
                    return {i1, i2};
                }
            }
        } 
        return {0,0};      
        }
    };

/*
! this is a brute force solution, it is not the most efficient way to solve this problem.
! the time complexity of this solution is O(n^2) which is not good.

* the best solution is to use a hash table to store the values and their indexes, then we can check if the difference between the target and the current value is in the hash table or not.
* the time complexity of this solution is O(n) which is the best we can get.
*
* it's logic is to store the values in a hash table and check if the difference between the target and the current value is in the hash table or not.
* if it is in the hash table, then we return the indexes of the two values.
* if it is not in the hash table, then we store the value in the hash table.
*/

/**
 * @brief  it's time complexity is O(n) and space complexity is O(n)
 * 
 */
class Solution2 {
    public:
        std::vector<int> twoSum(std::vector<int>& nums, int target) {
            std::unordered_map<int, int>map;
    
            for(int i = 0; i < nums.size(); i++){
                int check = target - nums[i];
                if(map.find(check) != map.end()){
                    return{map[check], i};
                }
    
                map[nums[i]] = i;
            }
        }
    };