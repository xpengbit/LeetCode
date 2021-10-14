/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(n, n, "", res);
        return res;    
    }
private:
    void helper(int l, int r, string out, vector<string>& res){
        if(l > r) return;
        if(l == 0 && r == 0) {
            res.push_back(out);
            return;
        }
        if(l > 0) helper(l - 1, r, out + '(', res);
        if(r > 0) helper(l,  r - 1, out + ')', res);
    }
};
// @lc code=end

