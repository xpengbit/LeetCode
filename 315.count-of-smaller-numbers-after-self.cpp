/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 */

// @lc code=start
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        //binary search(will TLE);
        /*vector<int> t, ret(nums.size());
        for(int i = nums.size() - 1; i >= 0; --i){
            auto iter = lower_bound(t.begin(), t.end(), nums[i]);
            ret[i] = iter - t.begin();
            t.insert(t.begin() + (iter - t.begin()), nums[i]);
        }
        return ret;*/

        //Divid and Conquer
        int n = nums.size();
        if(n == 0) return {};
        vector<int> sortednums = nums, ret(n, 0);
        dividConquer(nums, sortednums, ret, 0, n - 1);
        return ret;
    }

    void dividConquer(vector<int>& nums, vector<int>& sortednums, vector<int>& ret, int start, int end){
        if(start == end) return;
        int mid = start + (end - start)/2;
        dividConquer(nums, sortednums, ret, start, mid);
        dividConquer(nums, sortednums, ret, mid + 1, end);

        for(int i = start; i <= mid; ++i){
            auto iter = lower_bound(sortednums.begin() + mid + 1, sortednums.begin() + end + 1, nums[i]);
            ret[i] += iter - (sortednums.begin() + mid + 1);
        }

        sort(sortednums.begin() + start, sortednums.begin() + end + 1);
    }    
};
// @lc code=end

