/*
 * @lc app=leetcode id=1658 lang=cpp
 *
 * [1658] Minimum Operations to Reduce X to Zero
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        unordered_map<int, int> Map;
        int presum = 0;
        Map[0] = -1;
        for(int i = 0; i < n; ++i){
            presum += nums[i];
            if(Map.find(presum) == Map.end())
                Map[presum] = i;
        }

        int ret = INT_MAX;
        if(Map.find(x) != Map.end())
            ret = Map[x] + 1;

        int sufsum = 0;
        for(int b = n - 1; b >= 0; --b){
            sufsum += nums[b];
            if(Map.find(x - sufsum) != Map.end()){
                int a = Map[x - sufsum];
                if(a < b){
                    ret = min(ret, a + 1 + n - b);
                }
            }
        }
        return ret == INT_MAX ? -1 : ret;    
    }
};
// @lc code=end
//这个题本质就是前面取几个数，后面取几个数 和 == x
//这种两个变量的问题，可以想到two sum固定一个找另外一个。 
//这里用到了前缀和，后缀和。

