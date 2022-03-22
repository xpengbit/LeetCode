/*
 * @lc app=leetcode id=1569 lang=cpp
 *
 * [1569] Number of Ways to Reorder Array to Get Same BST
 */

// @lc code=start
class Solution {
public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        memo = vector<vector<long>>(n, vector<long>(n, -1));
        long res = (MOD + totalWays(nums) - 1) % MOD;
        return (int)res;        
    }
private:
    vector<vector<long>> memo;
    int MOD = (int)1e9 + 7;

    long nCk(int n, int k){
        if(k == 0 || n == k) return 1;
        if(k == 1) return n;
        if(memo[n][k] != -1) return memo[n][k];
        if(k > n - k) return nCk(n, n - k);
        return memo[n][k] = (nCk(n - 1, k - 1) + nCk(n - 1, k)) % MOD;
    }

    long totalWays(vector<int>& nums){
        if(nums.size() <= 2) return 1;
        vector<int> l, r;
        int head = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < head) l.push_back(nums[i]);
            else r.push_back(nums[i]);
        }
        long cnt = totalWays(l)* totalWays(r) % MOD;
        long comb = nCk(nums.size() - 1, l.size());
        return (cnt * comb) % MOD;
    }
};
// @lc code=end

