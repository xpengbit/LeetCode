/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */

// @lc code=start
class Solution {
public:
    int totalNQueens(int n) {
        vector<int> cur(n, -1);
        count = 0;
        dfs(cur, 0);
        return count;
    }
private:
    int count;
    void dfs(vector<int>& cur, int row){
        if(row == cur.size()){
            ++count; return;
        }
        for(int j = 0; j < cur.size(); ++j){
            if(!isValid(cur, row, j)) continue;
            cur[row] = j;
            dfs(cur, row + 1);
            cur[row] = -1;
        }
    }

    bool isValid(vector<int>& cur, int row, int col){
        for(int i = 0; i < row; ++i){
            if(cur[i] == col) return false;
            if(abs(i - row) == abs(cur[i] - col)) return false;
        }
        return true;
    }
};
// @lc code=end

