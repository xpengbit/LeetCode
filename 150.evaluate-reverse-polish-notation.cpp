/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size() ==  1) return stoi(tokens[0]);
        int n = tokens.size();
        stack<int> st;
        for(int i = 0; i < n; ++i){
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
                st.push(stoi(tokens[i]));
            else{
                int num1 = st.top(); st.pop();
                int num2 = st.top(); st.pop();
                if(tokens[i] == "+") st.push(num2 + num1);
                if(tokens[i] == "-") st.push(num2 - num1);
                if(tokens[i] == "*") st.push(num2 * num1);
                if(tokens[i] == "/") st.push(num2 / num1);
            }
        }
        return st.top();

        /*Recurcive Solution*/
        int cur = tokens.size() - 1;
        return helper(tokens, cur);
    }
private:
    int helper(vector<string>& tokens, int& cur){
        string str = tokens[cur];
        if(str != "+" && str != "-" && str != "*" && str != "/") 
            return stoi(str);
        int num1 = helper(tokens, --cur);
        int num2 = helper(tokens, --cur);
        if(str == "+") return num2 + num1;
        if(str == "-") return num2 - num1;
        if(str == "*") return num2 * num1;
        return num2 / num1;
    }
};
// @lc code=end

