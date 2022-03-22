class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);
        int mx = 1, ret = 1;
        for(int i = 1; i < n; ++i){
            for(int j = i - 1; j >= 0; --j){
                if(nums[j] < nums[i]){
                    if(dp[i] == dp[j] + 1) cnt[i] += cnt[j];
                    else if(dp[i] < dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }
                }
            }
            if(mx == dp[i]) ret += cnt[i];
            else if(mx < dp[i]){
                mx = dp[i];
                ret = cnt[i];
            }
        }
        return ret;
    }
};