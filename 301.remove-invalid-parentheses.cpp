/*
 * @lc app=leetcode id=301 lang=cpp
 *
 * [301] Remove Invalid Parentheses
 */

// @lc code=start
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> cur{{s}};
        vector<string> res;

        while(!cur.empty()){
            unordered_set<string> next;
            for(auto& a : cur){
                if(isValid(a)) res.push_back(a);
                if(!res.empty()) continue;
                for(int i = 0; i < a.size(); ++i){
                    next.insert(a.substr(0, i) + a.substr(i + 1));
                }
            }
            if(!res.empty()) break;
            cur = next;
        }
        return res;        
    }

    bool isValid(string s){
        int cnt = 0;
        for(char c : s){
            if(c == '(') cnt++;
            else if(c == ')' && --cnt < 0) return false;
        }
        return cnt == 0;
    }
};
// @lc code=end

