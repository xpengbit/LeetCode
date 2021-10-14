/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        /*int res = 0, n = height.size();
        vector<int> leftMax(n, 0);
        vector<int> rightMax(n, 0);
        for(int i = 1; i < n; ++i){
            leftMax[i] = max(leftMax[i - 1], height[i - 1]);
            rightMax[n - 1 - i] = max(rightMax[n - i], height[n - i]);
        }
        
        for(int i = 0; i < n; ++i){
            int h = min(leftMax[i], rightMax[i]);
            if(h > height[i])
                res += h - height[i];
        }
        return res;*/

        /*解法2-单调栈*/
        /*遍历高度，如果此时栈为空，或者当前高度小于等于栈顶高度，则把当前高度的坐标压入栈，
        注意这里不直接把高度压入栈，而是把坐标压入栈，这样方便在后来算水平距离。当遇到比栈顶高度大的时候，
        就说明有可能会有坑存在，可以装雨水。此时栈里至少有一个高度，如果只有一个的话，那么不能形成坑，直接跳过，
        如果多于一个的话，那么此时把栈顶元素取出来当作坑，新的栈顶元素就是左边界，当前高度是右边界，只要取二者较小的，
        减去坑的高度，长度就是右边界坐标减去左边界坐标再减1，二者相乘就是盛水量**/
        stack<int> s;
        int res = 0, n = height.size(), i = 0;
        while(i < n){
            if(s.empty() || height[s.top()] >= height[i]){
                s.push(i++);
            }
            else{
                int t = s.top(); s.pop();
                if(s.empty()) continue;
                res += (min(height[s.top()], height[i]) - height[t]) * (i - s.top() - 1);
            }
        }
        return res;
    }
};
// @lc code=end

