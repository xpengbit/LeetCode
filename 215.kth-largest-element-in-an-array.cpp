/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //binary search by value
        /*int l = INT_MIN / 2, r = INT_MAX / 2;
        while(l < r){
            int mid = r - (r - l) / 2;
            if(count(nums, mid) >= k) l = mid;
            else r = mid - 1;
        }
        return l;*/
        
        //quick select
        return quickSelect(nums, 0, nums.size() - 1, k);
    }
   
    int quickSelect(vector<int>& nums, int a, int b, int k){
        int pivot = nums[a + (b - a)/ 2];
        int i = a, t = a, j = b;
        while(t <= j){
            if(nums[t] < pivot){
                swap(nums[t], nums[i]);
                i++; t++;
            }
            else if(nums[t] > pivot){
                swap(nums[t], nums[j]);
                j--;
            }
            else t++;
        }

        if((b - j) >= k) return quickSelect(nums, j + 1, b, k);
        else if((b - i + 1) >= k) return pivot;
        else return quickSelect(nums, a, i - 1, k - (b - i + 1));
    }

    int count(vector<int>& nums, int k){
        int cnt = 0;
        for(int x : nums)
            cnt += (x >= k);
        return cnt;
    }
};
// @lc code=end

