/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

// @lc code=start
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        dfs(s, 0, "", res);
        return res;            
    }
private:
    bool isValid(string s){
        if(s.empty() || s.size() > 3 || (s.size() > 1 && s[0] == '0')) return false;
        int res = atoi(s.c_str());
        return res >= 0 && res <= 255;
    }
    void dfs(string s, int pos, string out, vector<string>& res){
        if(pos == 4){
            if(s.empty()){
                res.push_back(out);
                return;
            }
        }
        for(int i = 1; i <= 3; ++i){
            if(s.size() >= i && isValid(s.substr(0, i))){
                dfs(s.substr(i), pos + 1, out + s.substr(0, i) + (pos == 3 ? "" : "."), res);
            }
        }
    }
};
// @lc code=end

