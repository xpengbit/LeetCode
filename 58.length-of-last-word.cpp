/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        int right = s.length() - 1;
        while(right >= 0 && s[right] == ' ') --right;
        while(right >= 0 && s[right] != ' '){
            --right; ++res;
        }
        return res;        
    }
};
// @lc code=end

