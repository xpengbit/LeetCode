/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        if(target < matrix[0][0]) return false;
        if(target > matrix[m-1][n-1]) return false;
        
        int lo = 0, hi = m*n - 1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(matrix[mid/n][mid%n] == target) return true;
            else if(matrix[mid/n][mid%n] > target)
                hi = mid - 1;
            else 
                lo = mid + 1;
        }
        
        return false;
        
        /*use binary search two times*/
        /*int lo = 0, hi = m - 1;

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(matrix[mid][0] == target) return true;
            else if(matrix[mid][0] < target)
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        int row = lo - 1;
        lo = 0, hi = n - 1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(matrix[row][mid] == target) return true;
            else if(matrix[row][mid] < target)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        
        return false;*/     
    }
};
// @lc code=end

