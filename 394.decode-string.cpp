/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        stack<string> str;
        stack<int> times;
        string res;
        for(int i = 0; i < s.size(); ++i){
            if(isdigit(s[i])){
                int num = 0;
                while(i < s.size() && isdigit(s[i])){
                    num = num* 10 + (s[i] - '0');
                    ++i;
                }
                times.push(num);
                str.push(res);
                res = "";
            }
            else if(s[i] == ']'){
                int k = times.top(); times.pop();
                string tmp = res;
                for(int j = 0; j < k - 1; ++j){
                    res += tmp;
                }
                res = str.top() + res;
                str.pop();
            }
            else
                res += s[i];    
        }
        return res;    
    }
};
// @lc code=end

