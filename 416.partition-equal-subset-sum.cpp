/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        /*2-D dp*/
        /*int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) return false;
        int target = sum >> 1;
        int n = nums.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        for(int i = 0; i <= n; i++) dp[i][0] = true;
        for(int i = 1; i <= n;  i++){
            for(int j = 1; j <= target; j++){
                dp[i][j] = dp[i - 1][j];
                if(j - nums[i -1] >= 0) dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
        return dp[n][target];*/

        /*1- D solution*/
        /*定义一个一维的 dp 数组，其中 dp[i] 表示原数组是否可以取出若干个数字，其和为i。那么最后只需要返回 dp[target] 就行了。*/
        int sum = accumulate(nums.begin(), nums.end(), 0), target = sum >> 1;
        if(sum & 1) return false;
        
        vector<bool> dp(target + 1);
        dp[0] = true;
        for(int num : nums){
            for(int j = target; j >= num; j--){
                dp[j] = dp[j] || dp[j - num]; 
                cout << "num = "<< num << "j = " << j << "dp[j] = " << dp[j] << endl;
            }
        }
        return dp[target];
        /*bitset solution*/
        /*bitset<5001> bits(1);
        int sum = accumulate(nums.begin(), nums.end(), 0); 
        for(int num : nums)
            bits |= bits << num;
        return (sum % 2 == 0) && bits[sum >> 1] ;*/
    }
};
// @lc code=end

