/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        /*unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());
        return helper(s, dict);*/

        /*use DP solution*/
        unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());
        int n = s.length();
        vector<bool> dp = vector<bool>(n + 1, false);
        dp[0] = true;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < i; j++){
                if(dp[j] && dict.count(s.substr(j, i - j))) dp[i] = true;
            }
        }
        return dp[n];
    }
private:
    unordered_map<string, bool> memo;

    bool helper(string s, unordered_set<string> dict){
        if(memo.count(s)) return memo[s];
        if(dict.count(s)) return memo[s] = true;
        for(int j = 1; j < s.length(); j++){
            const string left = s.substr(0, j);
            const string right = s.substr(j);
            if(dict.count(right) && helper(left, dict))
                return memo[s] = true;
        }
        return memo[s] = false;
    }
    
};
// @lc code=end

