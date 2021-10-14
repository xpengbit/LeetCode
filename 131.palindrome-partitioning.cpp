/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s, int l, int r){
        while(l < r){
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
       if(s.empty()) return {};
       int n = s.size();
       vector<vector<string>> res;
       vector<string> tmp;
       dfs(s, 0, tmp, res);
       return res;
    }
private:
    void dfs(string& s, int start, vector<string>& tmp, vector<vector<string>>& res){
        if(start == s.size()){
            res.push_back(tmp);
            return;
        }
        for(int i = start; i < s.size(); ++i){
            if(!isPalindrome(s, start, i)) continue;
            tmp.push_back(s.substr(start, i - start + 1));
            dfs(s, i + 1, tmp, res);
            tmp.pop_back();
        }
    }
};
// @lc code=end

