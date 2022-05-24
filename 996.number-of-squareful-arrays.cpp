/*
 * @lc app=leetcode id=996 lang=cpp
 *
 * [996] Number of Squareful Arrays
 */

// @lc code=start
class Solution {
    vector<vector<int>> adj;
    vector<int> visited;
    int res = 0;
    int n;
public:
    int numSquarefulPerms(vector<int>& nums) {
        n = nums.size();
        adj.resize(n);
        visited.resize(n);
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(i == j) continue;
                if(sqrt(nums[i] + nums[j]) == (int)sqrt(nums[i] + nums[j]))
                    adj[i].push_back(j);
            }
        }

        for(int i = 0; i < n; ++i){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            visited[i] = 1;
            dfs(nums, i, 1);
            visited[i] = 0;
        }

        return res;
    }

    void dfs(vector<int>& nums, int i , int count){
        if(count == n){
            res++;
            return;
        }
        
        int last = -1;
        for(auto nxt : adj[i]){
            if(visited[nxt]) continue;
            if(nums[nxt] == last) continue;
            visited[nxt] =1;
            last = nums[nxt];
            dfs(nums, nxt, count + 1);
            visited[nxt] = 0;
        }
    }
};
// @lc code=end

