/*
 * @lc app=leetcode id=921 lang=cpp
 *
 * [921] Minimum Add to Make Parentheses Valid
 */

// @lc code=start
class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0, ret = 0;
        for(char c : s){
            if(c == '(') cnt++;
            if(c == ')') cnt--;
            if(cnt < 0){
                ret++;
                cnt = 0;
            }
        }
        ret += cnt;
        return ret;
    }
};
// @lc code=end
//这道题是一个Greedy; cnt 表示还没有匹配的左括号的数量。

