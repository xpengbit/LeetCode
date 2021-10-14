/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        /*vector<int> memo(n+1);
        return dfs(n, memo);*/

        /**/
        vector<int> f(n + 1, 0);
        f[0] = 1;
        f[1] = 1;
        for(int i = 2; i <= n; ++i){
            for(int k = 1; k <= i; ++k){
                f[i] += f[k - 1] * f[i - k];
            }
        }
        return f[n];   
    }
private:
    int dfs(int num, vector<int>& memo){
        if(num == 0 or num == 1) return 1;
        if(memo[num] != NULL) return memo[num];
        int sum = 0;
        for(int i = 1; i <= num; i++){
            sum += dfs(i-1, memo)*dfs(num -i, memo);
        }
        return memo[num] = sum;
    }
};
// @lc code=end

