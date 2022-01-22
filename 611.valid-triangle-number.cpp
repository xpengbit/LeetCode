/*
 * @lc app=leetcode id=611 lang=cpp
 *
 * [611] Valid Triangle Number
 */

// @lc code=start
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        //Two point (sliding window)
        int n = nums.size();
        if(n < 3) return 0;
        sort(nums.begin(), nums.end());
        int cnt = 0;
        for(int k = n - 1; k >= 2; --k){
            int j = k - 1, i = 0;
            while(i < j){
                if(nums[i] + nums[j] > nums[k]){
                    cnt += j - i;
                    j--;
                }
                else
                    i++;
            }
        }
        return cnt;
    }
};
// @lc code=end

