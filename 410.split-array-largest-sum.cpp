/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 */

// @lc code=start
class Solution {
public:
/*Similiar problem 1283,1292,1482,1552*/
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        int largest = 0;
        int sum = 0;
        for(int i : nums){
            largest = max(largest, i);
            sum += i;
        }
        int lo = largest;
        int hi = sum;
        while(lo < hi){
            int mid = lo + (hi-lo)/2;
            int pieces = split(nums, mid);
            if(pieces > m)
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo; 
    }
private:
    int split(vector<int>& nums, int largestSum){
        int pieces = 1;
        int sum = 0;
        for(int num : nums){
            if(sum + num > largestSum){
                sum = num;
                pieces++;
            }
            else{
                sum += num;
            }
        }
        return pieces;
    }
};
// @lc code=end

