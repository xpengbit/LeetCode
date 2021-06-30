/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*O(m+n) Solution*/
        int m = matrix.size();
        int n = matrix[0].size();

        int row = 0, col = n - 1;
        while(row < m and col >= 0){
            if(matrix[row][col] > target)
                col--;
            else if(matrix[row][col] < target)
                row++;
            else
                return true;
        }

        return false;
        /*Binary Search O(mlogn) Time Complicity*/
        /*int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i = 0; i < m; i++){
            int lo = 0, hi = n;
            while(lo < hi){
                int mid = lo + (hi - lo)/2;
                if(matrix[i][mid] == target) return true;
                else if(matrix[i][mid] > target)
                    hi = mid;
                else
                    lo = mid + 1;
            }
        }
        return false;*/
    }
};
// @lc code=end

