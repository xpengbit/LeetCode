/*
 * @lc app=leetcode id=1186 lang=cpp
 *
 * [1186] Maximum Subarray Sum with One Deletion
 */

// @lc code=start
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size(), ret = arr[0];
        int dp[n][2];

        dp[0][0] = arr[0];
        dp[0][1] = 0;
        for(int i = 1; i < n; ++i){
            dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
            dp[i][1] = max(dp[i - 1][1] + arr[i], dp[i - 1][0]);

            ret = max(ret, max(dp[i][0], dp[i][1]));
        }
        return ret;
    }
};
// @lc code=end

//kadane 算法求一个数组里最大子数组的和。现在可以删除一个元素。
//dp[i][0] 表示没有使用删除的以i结尾的最大子数组的和。
//dp[i][1] 表示使用过一次删除的以i结尾的最大子数组的和。

