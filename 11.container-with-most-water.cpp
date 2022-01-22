/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        /*双指针解法*/
        int area = 0, i = 0, j = height.size() - 1;
        while(i < j){
            area = max(area, (j - i) * min(height[i], height[j]));
            height[i] < height[j] ? ++i : --j;
        }
        return area;
    }
};
// @lc code=end

