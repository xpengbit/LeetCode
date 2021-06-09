/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        if(mat.size() == 0) return res;
        queue<vector<int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    res[i][j] = 0;
                    q.push({i, j});
                }
                else{
                    res[i][j] = INT_MAX;
                }
            }
        }
        while(!q.empty()){
            int min = 0;
            vector<int> tmp = q.front();
            q.pop();
            for(auto d : dir){
                int x = tmp[0] + d[0];
                int y = tmp[1] + d[1];
                if(x >= 0 and x < m and y >= 0 and y < n){
                    if(res[x][y] > res[tmp[0]][tmp[1]] + 1){
                        res[x][y] = res[tmp[0]][tmp[1]] + 1;
                        q.push({x,y});
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

