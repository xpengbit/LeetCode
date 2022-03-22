/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() == 0) return 0;
        int n = s.size();
        stack<int> stk;
        int ret = 0;
        for(int i = 0; i < n; ++i){
            if(s[i] == '(') stk.push(i);
            else{
                if(!stk.empty() && s[stk.top()] == '('){
                    stk.pop();
                    res = max(res, stk.empty() ? i + 1 : i - stk.top());
                }
                else
                    stk.push(i);
            }
        }
        return res;
        /*int res = 0, start = 0, n = s.size();
        stack<int> st;
        for(int i = 0; i < n; ++i){
            if(s[i] == '(') {
                st.push(i);
            }
            else if(s[i] == ')'){
                if(st.empty()) start = i + 1;
                else {
                    st.pop();
                    res = st.empty() ? max(res, i - start + 1) : max(res, i - st.top());
                }
            }
        }
        return res;*/
        /*方法2：两遍扫描*/
        int res = 0, left = 0, right = 0, n = s.size();
        for(int i = 0; i < n; ++i){
            s[i] == '(' ? ++left : ++right;
            if(left == right) res = max(res, 2 * right);
            else if(right > left) left = right = 0;
        }
        left = right = 0; /*situation "(()"*/
        for(int i = n - 1; i >= 0; --i){
            s[i] == '(' ? ++left : ++right;
            if(right == left) res = max(res, 2 * left);
            else if(left > right) left = right = 0;
        }
        return res;    
    }
};
// @lc code=end

