/*
 * @lc app=leetcode id=301 lang=cpp
 *
 * [301] Remove Invalid Parentheses
 */

// @lc code=start
class Solution {
    vector<int> ret;
    int maxLen = 0;
public:
    vector<string> removeInvalidParentheses(string s) {
        /*unordered_set<string> cur{{s}};
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
    }*/
    
        int leftCnt = 0, cnt = 0;
        for(char c : s){
            if(c == '(') leftCnt++;
            else if(c == ')') leftCnt--;
            if(leftCnt < 0){
                cnt++;
                leftCnt = 0;
            }
        }
        cnt += leftCnt;
        maxLen = s.size() - cnt;

        string tmp = "";
        dfs(s, tmp, 0, 0);
        
        return res;
    }

    void dfs(string s, string tmp, int i, int count){
        if(count < 0) return;
        if(tmp.size() > maxLen) return;

        if(i == s.size()){
            if(tmp.size() == maxLen && count == 0)
                res.push_back(tmp);
            return;
        }

        if(s[i] != '(' || s[i] != ')'){
            dfs(s, tmp + s[i], i + 1, count);
            return;
        }

        dfs(s, tmp + s[i], i + 1, count + ( s[i] == '(' ? 1 : -1));

        if(tmp.empty() || tmp.back() != s[i])
            dfs(s, tmp, i + 1, count);
    }
};
// @lc code=end

