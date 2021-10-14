/*
 * @lc app=leetcode id=1208 lang=cpp
 *
 * [1208] Get Equal Substrings Within Budget
 */

// @lc code=start
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int curCost = 0, res = 0, start = 0, n = s.size();
        for(int i = 0; i < n; ++i){
            curCost += abs(s[i] - t[i]);
            while(curCost > maxCost && start <= i){
                curCost -= abs(s[start] - t[start]);
                start++;
            }
            res = max(res, i - start + 1);
        }
        return res; 
    }
};
// @lc code=end

