/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        /*超时*/
        /*int res = 0;
        for(int i = 0; i < heights.size(); ++i){
            if(i + 1 < heights.size() && heights[i] <= heights[i + 1]) continue;
            int minH = heights[i];
            for(int j = i; j >= 0; --j){
                minH = min(minH, heights[j]);
                int area = minH * (i - j + 1);
                res = max(res, area);
            }
        }
        return res;*/

        /*单调栈*/
        int res = 0;
        stack<int> st;
        heights.push_back(0);
        for(int i = 0; i < heights.size(); ++i){
            while(!st.empty() && heights[i] < heights[st.top()]){
                int cur = st.top(); st.pop();
                res = max(res, heights[cur] * (st.empty() ? i : (i - st.top() - 1)));
            }
            st.push(i);
        }
        return res;
    }
};
// @lc code=end

