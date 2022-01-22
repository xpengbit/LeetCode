/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 */

// @lc code=start
class Solution {
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0] == b[0])
            return a[1] > b[1];
        else
            return a[0] < b[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //nlogn 
        /*sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> arr;
        for(auto x : envelopes){
            auto it = lower_bound(arr.begin(), arr.end(), x[1]);
            if(it == arr.end())
                arr.push_back(x[1]);
            else
                *it = x[1];
        }
        return arr.size();*/
       
        //N^2 will TLE
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end());
        vector<int> dp(n, 1);
        int ret = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < i; ++j){
                if(envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            ret = max(ret, dp[i]);
        }
        return ret;   
    }
};
// @lc code=end

