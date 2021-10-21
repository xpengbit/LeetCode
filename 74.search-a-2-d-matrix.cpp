/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*很巧妙的解法， 由左下角开始，搜索到右上角*/
        int m = matrix.size(), n = matrix[0].size();
        if(m == 0 || n == 0) return false; 
        int i = m - 1, j = 0;
        while(i >= 0 && j < n){
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] < target) ++j;
            else --i;
        }
        return false;
        
        /*int m = matrix.size();
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
        
        return false;*/
        
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

