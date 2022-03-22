/*
 * @lc app=leetcode id=1574 lang=cpp
 *
 * [1574] Shortest Subarray to be Removed to Make Array Sorted
 */

// @lc code=start
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size(), j = n - 1;
        int res = n - 1;

        while(j - 1 >= 0 && arr[j - 1] <= arr[j])
            j--;
        res = min(res, j);
        if(res == 0) return 0; //arr是一个递增序列

        for(int i = 0; i < n; ++i){
            if(i >= 1 && arr[i] < arr[i - 1]) break;
            while(j < n && arr[j] < arr[i])
                j++;
            
            res = min(res, j - i - 1);
        }
        return res;    
    }
};
// @lc code=end

