/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        const int m = haystack.size(), n = needle.size();
        if(m < n) return -1;
        for(int i = 0; i <= m - n; ++i){
            int j = 0;
            for(; j < n; ++j){
                if(haystack[i + j] != needle[j]) break;
            }
            if(j == n) return i;
        }
        return -1;
    }
};
// @lc code=end

