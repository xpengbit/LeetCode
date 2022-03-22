/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), cur = 0, pre = 0, i = 0, res = 0;
        while(cur < n - 1){ //n - 1 means 已经抵达，so should be < n - 1;
            pre = cur;
            for( ;i <= pre; ++i){
                cur = max(cur, i + nums[i]);
            }
            res++;
        }
        return res;
    }
};
// @lc code=end

