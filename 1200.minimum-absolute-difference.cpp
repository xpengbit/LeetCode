/*
 * @lc app=leetcode id=1200 lang=cpp
 *
 * [1200] Minimum Absolute Difference
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        const size_t n = arr.size();
        int diff = INT_MAX;
        sort(begin(arr), end(arr));
        for(int i = 1; i < n; ++i){
            int mn = arr[i] - arr[i - 1];
            if(mn <= diff){
                if(mn < diff) res.clear();
                diff = mn;
                res.push_back({arr[i - 1], arr[i]});
            }
        }
        return res;
    }
};
// @lc code=end

