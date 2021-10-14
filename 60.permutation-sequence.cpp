/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */

// @lc code=start
class Solution {
public:
    string getPermutation(int n, int k) {
        /*可以调用n - 1次 nextPermutation (LeetCode 31)*/
        /*这里的解法采用康托编码*/
        string res;
        string num = "123456789";
        vector<int> factor(n, 1);
        for(int i = 1; i < n; i++) factor[i] = factor[i -1] * i;
        k--;
        for(int i = n; i >= 1; --i){
            int j = k / factor[n - 1];
            k %= factor[n - 1];
            res.push_back(num[j]);
            num.erase(j, 1);
        }
        return res;
    }
};
// @lc code=end

