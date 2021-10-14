/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j){
            if(!isalnum(s[i])) ++i;
            else if(!isalnum(s[j])) --j;
            else if((s[i] + 32 - 'a') % 32 != (s[j] + 32 - 'a') % 32) return false;
            else{
                ++i; --j;
            }
        }
        return true;
    }
};
// @lc code=end

