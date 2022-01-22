/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0, n = s.size(), start = 0;
        stack<int> s;
        for(int i = 0; i < n; ++i){
            if(s[i] == '(') s.push(i);
            else{
                if(s.empty()) start = i + 1;
                else{
                    s.pop();
                    res = max(res, s.empty() ? i - start + 1 : i - s.top());
                }
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

