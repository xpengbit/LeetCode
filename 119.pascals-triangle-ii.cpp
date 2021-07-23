/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        /*vector<int> res(rowIndex + 1);
        res[0] = 1;
        for(int i = 1; i <= rowIndex; i++){
            vector<int> pre(res);
            for(int j = 1; j < i; j++){
                res[j] = pre[j] + pre[j -1];
            }
            res[i] = 1;
        }
        return res;*/
        vector<int> res(rowIndex + 1);
        res[0] = 1;
        for(int i = 1; i <= rowIndex; i++){
            for(int j = i; j >= 1; j--)
                res[j] += res[j - 1];
        }
        return res;
    }
};
// @lc code=end

