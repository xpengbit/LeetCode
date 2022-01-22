/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 */

// @lc code=start
class Solution {
public:
    vector<int> grayCode(int n) {
        /*Mirror Arrangement*/
        vector<int> res{0};
        for(int i = 0; i < n; ++i){
            int m = res.size();
            for(int j = m - 1; j >= 0; --j)
                res.push_back(res[j] | 1 << i);
        }
        return res;
    }
};
// @lc code=end

