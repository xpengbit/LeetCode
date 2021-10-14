/*
 * @lc app=leetcode id=1191 lang=cpp
 *
 * [1191] K-Concatenation Maximum Sum
 */

// @lc code=start
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        const int kMod = 1e9 + 7;
        if(k < 3) return sumMax(arr, k) % kMod;
        long ans1 = sumMax(arr, 1);
        long ans2 = sumMax(arr, 2);
        long sum = accumulate(begin(arr), end(arr), 0L);
        return max({ans1, ans2, ans2 + (k - 2)*sum}) % kMod;   
    }
private:
    long sumMax(vector<int>& arr, int k){
        long res = 0, sum = 0;
        for(int i = 0; i < k; ++i){
            for(int a : arr){
                sum = max(0L, sum += a);
                res = max(res, sum);
            }
        }
        return res;
    }
};
// @lc code=end

