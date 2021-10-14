/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 */

// @lc code=start
/*class Solution {
public:
    vector<int> nums;
    vector<char> ops;
    vector<int> dp[21][21];

    vector<int> diffWaysToCompute(string expression) {
        for(int i = 0; i < expression.size(); ++i){
            int j = i;
            while(j < expression.size() && isdigit(expression[j]))
                ++j;
            nums.push_back(stoi(expression.substr(i, j - i)));
            if(j < expression.size()) ops.push_back(expression[j]);
            i = j;
        }
        int n = nums.size();
        helper(0, n - 1);
        return dp[0][n - 1];    
    }
private:
    void helper(int a, int b){
        if(!dp[a][b].empty()) return;
        if(a == b){
            dp[a][b] = {nums[a]};
            return;
        }
        for(int i = a; i < b; ++i){/*这里是遍历操作符，比操作数少一位*/
     /*       helper(a, i);
            helper(i + 1, b);

            for(auto x : dp[a][i]){
                for(auto y : dp[i + 1][b]){
                    if(ops[i] == '+')
                        dp[a][b].push_back(x + y);
                    else if(ops[i] == '-')
                        dp[a][b].push_back(x - y);
                    else if(ops[i] == '*')
                        dp[a][b].push_back(x * y);
                }
            }
        }
    }
};*/

class Solution {
public:
    unordered_map<string, vector<int>> memo;
    vector<int> diffWaysToCompute(string expression) {
        if(memo.count(expression)) return memo[expression];
        vector<int> res;
        for(int i = 0; i < expression.size(); ++i){
            if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*'){
                vector<int> a = diffWaysToCompute(expression.substr(0, i));
                vector<int> b = diffWaysToCompute(expression.substr(i + 1));
                for(auto x : a){
                    for(auto y : b){
                        if(expression[i] == '+')
                            res.push_back(x + y);
                        else if(expression[i] == '-')
                            res.push_back(x - y);
                        if(expression[i] == '*')
                            res.push_back(x * y);
                    }
                }
            }
        }
        if(res.empty()) res.push_back(stoi(expression));
        memo[expression] = res;
        return res;
    }
};
// @lc code=end

