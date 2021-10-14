/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        int sum = 0, i = 0;
        const int n = s.length();
        int sign = 1;
        while(i < n && s[i] == ' ') ++i;
        if(i < n && (s[i] == '+' || s[i] == '-'))
            sign = s[i++] == '+' ? 1 : -1;
        while(i < n && s[i] >= '0' && s[i] <= '9'){
            if(sum > INT_MAX / 10 || (sum == INT_MAX / 10 && s[i] - '0' > 7))
                return sign == 1 ? INT_MAX : INT_MIN;
            sum = sum * 10 + (s[i++] - '0');
        }
        return sum * sign;
    }
};
// @lc code=end

