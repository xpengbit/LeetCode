/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        /*const size_t m = matrix.size();
        const size_t n = matrix[0].size();
        vector<bool> row(m, false);
        vector<bool> col(n, false);

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(matrix[i][j] == 0){
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
        for(int i = 0; i < m; ++i){
            if(row[i])
                fill(matrix[i].begin(), matrix[i].end(), 0);
        }
        for(int j = 0; j < n; ++j){
            if(col[j]){
                for(int i = 0; i < m; ++i)
                    matrix[i][j] = 0;
            }
        }        
    }*/
    const size_t m = matrix.size();
    const size_t n = matrix[0].size();
    bool firstRow = false, firstCol = false;
    for(int i = 0; i < m; ++i){
        if(matrix[i][0] == 0) firstCol = true;
    }
    for(int j = 0; j < n; ++j){
        if(matrix[0][j] == 0) firstRow = true;
    }
    for(int i = 1; i < m; ++i){
        for(int j = 1; j < n; ++j){
            if(matrix[i][j] == 0){
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }
    for(int i = 1; i < m; ++i){
        for(int j = 1; j < n; ++j){
            if(matrix[0][j] == 0 || matrix[i][0] == 0)
                matrix[i][j] = 0;
        }
    }
    if(firstRow == true){
        for(int j = 0; j < n; ++j) matrix[0][j] = 0;
    }
    if(firstCol == true){
        for(int i = 0; i < m; ++i) matrix[i][0] = 0;
    }
    }
};
// @lc code=end

