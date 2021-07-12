/*
 * @lc app=leetcode id=1713 lang=cpp
 *
 * [1713] Minimum Operations to Make a Subsequence
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> targetMap;
        vector<int> nums(arr.size());
        for(int i = 0; i < target.size(); i++) targetMap[target[i]] = i;
        for(int i = 0; i < arr.size(); i++){
            if(targetMap.count(arr[i]))
                nums[i] = targetMap[arr[i]];
            else
                nums[i] = -1;
        }
        return target.size() - lengthOfLIS(nums);
    }
private:
    /*把target数组元素如果在arr中存在的话， 把target元素的位置存成一个数组，然后找这个数组的LIC*/
    int lengthOfLIS(vector<int> nums){
        vector<int> dp(nums.size());
        int len = 0;
        int size = 0;
        for(int num : nums){
            if(num == -1) continue;
            int pos = binarySearch(dp, size, num);
            dp[pos] = num;
            if(pos == size) size++;
        }
        return size;
    }

    int binarySearch(vector<int> dp, int size, int target){
        int l = 0, r = size;
        while(l < r){
            int mid = l + (l - r)/2;
            if(dp[mid] < target)
                l = mid + 1;
            else 
                r = mid;
        }
        return l;
    }
};
// @lc code=end

