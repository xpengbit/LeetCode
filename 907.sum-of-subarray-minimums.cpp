/*
 * @lc app=leetcode id=907 lang=cpp
 *
 * [907] Sum of Subarray Minimums
 */

// @lc code=start
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nextSmaller(n, n); //i之后没有任何一个元素小于i，则i右边可以延伸到数组末尾。则个数为 n - i;
        vector<int> preSmaller(n, -1); //i之前没有任何一个元素小于i，则i左边可以延伸到开始的左边。（i - 0 + 1）数组初始化为-1；
        stack<int> Stack;

        for(int i = 0; i < n; ++i){
            while(!Stack.empty() && arr[Stack.top()] > arr[i]){
                nextSmaller[Stack.top()] = i;
                Stack.pop();
            }
            Stack.push(i);
        }

        while(!Stack.empty()) Stack.pop();
        for(int i = n - 1; i >= 0; --i){
            while(!Stack.empty() && arr[Stack.top()] >= arr[i]){
                preSmaller[Stack.top()] = i;
                Stack.pop();
            }
            Stack.push(i);
        }
        
        long ret = 0;
        long M = 1e9 + 7;
        for(int i = 0; i < n; ++i){
            long sum = arr[i] * (i - preSmaller[i]) % M * (nextSmaller[i] - i);
            ret = (ret + sum) % M;
        }

        return ret;        
    }
};
// @lc code=end

//这道题求数组arr每一个子数组最小值的和。如果遍历每一个元素，然后再遍历每一个子数组，这样是一个n^2的解法,会TLE.
//另外一个非常巧妙的思路。不找每个subarr的最小值， 而是遍历数组每一个元素，找以这个元素为最小值的subarr。这样，这个问题
//就转变为了找每一个元素的 preSmaller 和 nextSmaller, 转化为了单调栈！arr[i] *(nextSmaller - i) * (i - preSmaller);
//还有一个不会想到的点：数组里有相同元素，这样的话，上面的思路就会有重复。这样可以做一个约定，约定如果相同元素，最左边
//的元素最小。这样求preSmaller 遇到相同元素需要停下来。
