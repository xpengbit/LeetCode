/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> map;
        vector<int> res;

        for(int i = 0; i < n; i++){
            int tmp = target - nums[i];
            if(map.count(tmp)){
                res = {map[tmp], i};
                return res;
            }
            map[nums[i]] = i;
        }
        return res;
    }
};
// @lc code=end

