/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int begin = 0, end = n - 1;
        int num = 1;
        while(begin < end){
            for(int j = begin; j < end; ++j) res[begin][j] = num++;
            for(int i = begin; i < end; ++i) res[i][end] = num++;
            for(int j = end; j > begin; --j) res[end][j] = num++;
            for(int i = end; i > begin; --i) res[i][begin] = num++;
            ++begin;
            --end;
        }

        if(begin == end) res[begin][begin] = num;
        return res;    
    }
};
// @lc code=end

