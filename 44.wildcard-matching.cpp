/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        const int m = s.size(), n = p.size();
        int i = 0, j = 0, istar = -1, jstar = -1;
        while(i < m){
            if(j < n && (s[i] == p[j] || p[j] == '?')){
                ++i; ++j;
            }
            else if(j < n && p[j] == '*'){
                istar = i;
                jstar = j;
                j++;
            }
            else if(istar >= 0){
                i = ++istar;
                j = jstar + 1;
            }
            else return false;
        }
        while(j < n && p[j] == '*') ++j;
        return j == n; 
    }
};
// @lc code=end

