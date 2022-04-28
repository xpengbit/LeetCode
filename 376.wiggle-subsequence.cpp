/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 */

// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        int up =1, down = 1;
        for(int i = 1; i < n; ++i){
            int old_up = up, old_down = down;
            if(nums[i] > nums[i - 1])
                up = old_down + 1;
            else if(nums[i] < nums[i - 1])
                down = old_up + 1;
        }
        return max(up, down);
    }
};
// @lc code=end

