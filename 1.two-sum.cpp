/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map; 

        for(int i = 0; i < nums.size(); i++){
            int diff = target - nums[i];
            if(map.count(diff))  return {map[diff], i};
            map[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end

