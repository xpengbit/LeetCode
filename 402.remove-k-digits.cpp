/*
 * @lc app=leetcode id=402 lang=cpp
 *
 * [402] Remove K Digits
 */

// @lc code=start
class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == 0) return num;
        if(k >= num.size()) return "0";
        stack<char> s;

        for(char c : num){
            while(!s.empty() && c < s.top() && k > 0){
                s.pop();
                k--;
            }
            s.push(c);
            if(s.size() == 1 && c == '0')  //pop begin with '0'
                s.pop();
        }

        while(!s.empty() && k > 0){
            s.pop();
            k--;
        }
        
        string res = "";
        while(!s.empty()){
            res = s.top() + res;
            s.pop();
        }

        if(res == "") return "0";
        return res;
    }
};
// @lc code=end

