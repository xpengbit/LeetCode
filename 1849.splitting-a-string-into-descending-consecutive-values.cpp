/*
 * @lc app=leetcode id=1849 lang=cpp
 *
 * [1849] Splitting a String Into Descending Consecutive Values
 */

// @lc code=start
typedef long long LL;
class Solution {
public:
    bool splitString(string s) {
        LL sum = 0;
        for(int i = 0; i < s.size() - 1; ++i){
            sum = sum * 10 + (s[i] - '0');
            if(sum > 1e10) break;
            if(dfs(s, i + 1, sum))
                return true;
        }
        return false;
    }

    bool dfs(string s, int cur, LL sum){
        if(cur == s.size()) return true;
        LL sum2 = 0;
        for(int i = cur; i < s.size(); ++i){
            sum2 = sum2 * 10 + (s[i] - '0');
            if(sum2 > 1e10) break;
            if(sum - 1 == sum2 && dfs(s, i + 1, sum2))
                return true;
        }
        return false;
    }
};
// @lc code=end

