/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */

// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;
        vector<int> height(n, 0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '0') height[j] = 0;
                else
                    height[j] += 1;
            }
            res = max(res, calculateRectangleArea(height, 0, n - 1));
        }
        return res;
    }
private:
    int calculateRectangleArea(vector<int>& height, int low, int high){
        if(low > high) return 0;
        int minHightIndex = low;
        for(int i = low + 1; i <= high; i++){
            if(height[i] < height[minHightIndex]) minHightIndex = i;
        }
        int curArea = height[minHightIndex] * (high - low + 1);
        int left = calculateRectangleArea(height, low, minHightIndex - 1);
        int right = calculateRectangleArea(height, minHightIndex + 1, high);
        int res = max(curArea, max(left, right));
        return res;
    }
};
// @lc code=end

