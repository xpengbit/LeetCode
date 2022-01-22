/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        /*int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return 1;
        int res = 1;
        vector<int> dp(n, 1);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < i; ++j){
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
        return res;*/

        vector<int> arr;
        for(int num : nums){
            auto it = lower_bound(arr.begin(), arr.end(), num);
            if(it == arr.end())
                arr.push_back(num);
            else
                *it = num;
        }
        return arr.size();
        /*int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return 1;
        vector<int> lens{nums[0]};
        for(int i = 1; i < n; ++i){
            if(nums[i] < lens[0]) lens[0] = nums[i];
            else if(nums[i] > lens.back()) lens.push_back(nums[i]);
            else{
                int l = 0, r = lens.size();
                while(l < r){
                    int mid = l + (r - l) / 2;
                    if(lens[mid] < nums[i]) l = mid + 1;
                    else r = mid;
                }
                lens[left] = nums[i];
            }
        }
        return lens.size();*/

    }
};
// @lc code=end

