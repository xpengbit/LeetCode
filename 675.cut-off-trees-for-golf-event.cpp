/*
 * @lc app=leetcode id=675 lang=cpp
 *
 * [675] Cut Off Trees for Golf Event
 */

// @lc code=start
class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int ret = 0, m = forest.size(), n = forest[0].size(), r = 0, c = 0;
        vector<vector<int>> tree;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(forest[i][j] > 1) tree.push_back({forest[i][j], i, j});
            }
        }
        sort(tree.begin(), tree.end());

        for(int i = 0; i < tree.size(); ++i){
            int cnt = bfs(forest, r, c, tree[i][1], tree[i][2]);
            if(cnt == -1) return -1;
            ret += cnt;
            r = tree[i][1];
            c = tree[i][2];
        }
        return ret;    
    }

    int bfs(vector<vector<int>>& forest, int r, int c, int tr, int tc){
        if(r == tr && c == tc) return 0;
        int m = forest.size(), n = forest[0].size(), ret = 0;
        vector<vector<int>> visited(m, vector<int>(n));
        visited[r][c] = 1;
        vector<pair<int, int>> d {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;
        q.push({r, c});
        while(!q.empty()){
            ret++;
            for(int k = q.size(); k > 0; --k){
                auto tmp = q.front(); q.pop();
                for(int i = 0; i < 4; ++i){
                    int x = tmp.first + d[i].first, y = tmp.second + d[i].second;
                    if(x < 0 || y < 0 || x >= m || y >= n || visited[x][y] == 1 || forest[x][y] == 0) continue;
                    if(x == tr && y == tc) return ret;
                    visited[x][y] = 1;
                    q.push({x, y});
                }
            }
        }
        return -1;
    }
};
// @lc code=end

