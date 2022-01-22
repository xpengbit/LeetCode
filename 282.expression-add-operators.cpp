/*
 * @lc app=leetcode id=282 lang=cpp
 *
 * [282] Expression Add Operators
 */

// @lc code=start
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        dfs(num, (long long)target, 0, 0, "", res);
        return res;
    }

    void dfs(string num, long long target, long long curSum, long long diff, string expre, vector<string>& res){
        if(num.size() == 0 && target == curSum){
            res.push_back(expre);
            return;
        }

        for(int i = 1; i <= num.size(); ++i){
            string cur = num.substr(0, i);
            if(cur.size() > 1 && cur[0] == '0') return;
            string next = num.substr(i);
            if(expre.size() > 0){
                dfs(next, target, curSum + stoll(cur), stoll(cur), expre + "+" + cur, res);
                dfs(next, target, curSum - stoll(cur), -stoll(cur), expre + "-" + cur, res);
                dfs(next, target, (curSum - diff) + diff*stoll(cur), diff * stoll(cur), expre + "*"+ cur, res);
            } 
            else
                dfs(next, target, stoll(cur), stoll(cur), cur, res);
        }
    }
};
// @lc code=end

