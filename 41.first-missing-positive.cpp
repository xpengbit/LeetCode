/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        nums.insert(nums.begin(), 0); //插入0使得索引跟数值正好匹配
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i]] != nums[i])
                swap(nums[i], nums[nums[i]]);
        }
        for(int i = 0; i < n; ++i){
            if(nums[i] != i) return i;
        }
        return nums.size();
    }
};
// @lc code=end

