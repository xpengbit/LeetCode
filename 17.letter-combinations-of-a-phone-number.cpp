/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        vector<string> dict{"", "","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        dfs(digits, dict, 0, "", res);
        return res;
    }
private:
    void dfs(string& digits, vector<string> dict, int pos, string out, vector<string>& res){
        if(pos == digits.size()) {res.push_back(out); return;}
        string str = dict[digits[pos] - '0'];
        for(int i = 0; i < str.size(); ++i){
            dfs(digits, dict, pos + 1, out + str[i], res);
        }
    }
};
// @lc code=end

