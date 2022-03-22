/*
 * @lc app=leetcode id=1392 lang=cpp
 *
 * [1392] Longest Happy Prefix
 */

// @lc code=start
class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> dp(n, 0); //dp[i]表示以i结尾的Happy prefix的长度。
        dp[0] = 0;
        for(int i = 1; i < n; ++i){
            int j = dp[i - 1];
            while(j >= 1 && s[j] != s[i])
                j = dp[j - 1];
            dp[i] = j + (s[j] == s[i]);
        }
        int len = dp[n - 1];
        return s.substr(0, len);
    }
};
// @lc code=end

//这个题求最长后缀数组。
//dp[i] 表示以i结尾的happy prefix的长度。k s[0: k-1] == s[i - k + 1:i]
//求dp[n - 1]
// * * * * * * * * * * * * * * * * * *  X -------------------- * * * * * * * * * * * * * * * * * *  Y
//                                  j-1,j                                                       i-1,i
// + + + + + Z-------------- + + + + +  X -------------------- ------------------------- + + + + +  Y
//        j'-1                      j-1,j                                                       i-1,i

// dp[i] = ? 
//假设 j = dp[i - 1], 那么if(s[j] == s[i]) dp[i] == j + 1
//j' = dp[j - 1]
//if(s[j'] == s[i]) dp[i] == j' + 1;
//j'' = dp[j' - 1]
