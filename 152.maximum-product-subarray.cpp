/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int res = nums[0];
        int mx = res, mn = res;
        for(int i = 1; i < nums.size(); i++){
            /*if(nums[i] > 0){
                mx = max(mx * nums[i], nums[i]);
                mn = min(mn * nums[i], nums[i]);
            }
            else{
                int t = mx;
                mx = max(mn * nums[i], nums[i]);
                mn = min(mx * nums[i], nums[i]);
            }*/
            if(nums[i] < 0) swap(mx, mn);
            mx = max(nums[i], nums[i]*mx);
            mn = min(nums[i], nums[i]*mn);
            res = max(res, mx);
        }
        return res;
    }
};
// @lc code=end

