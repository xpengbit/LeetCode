/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lo = 0, hi = numbers.size() - 1;
        while(lo < hi){
            if(numbers[lo] + numbers[hi] == target)
                return {lo + 1, hi + 1};
            else if(numbers[lo] + numbers[hi] > target)
                hi--;
            else 
                lo++;
        }        
        return {-1, -1};

        /*binary search time complexity is O(nlogn)*/
        /*vector<int> res;
        int n = numbers.size();
        for(int i = 0; i < n - 1; i++){
            int lo = i + 1, hi = n - 1;
            while(lo <= hi){
                int mid = lo + (hi - lo)/2;
                if(numbers[mid] == target-numbers[i]){
                    res = {i+1, mid+1};
                    return res;
                }
                else if(numbers[mid] > target-numbers[i])
                    hi = mid - 1;
                else
                    lo = mid + 1;
            } 
        }
        return res;*/   
    }
};
// @lc code=end

