/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */

// @lc code=start
/*class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        long l = INT_MIN, r = INT_MAX;
        while(l < r){
            long mid = l + (r - l) / 2;
            if(LowerOrEqual(mid, matrix) < k) l = mid + 1;
            else r = mid; 
        }
        return l;    
    }

    int LowerOrEqual(long mid, vector<vector<int>>& matrix){
        int cnt = 0, i = matrix.size() - 1, j = 0;
        while(i >= 0 && j < matrix[0].size()){
            if(matrix[i][j] <= mid){
                cnt += (i + 1);
                j++;
            }
            else
                --i;
        }
        return cnt;
    }
};
*/

class Solution {
    int M, N;
    struct cmp{
        bool operator()(pair<int, int> a, pair<int, int> b) {
            return a.first >= b.first;
        }
    };
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        M = matrix.size();
        N = matrix[0].size();
        vector<vector<int>> visited(M, vector<int>(N, 0));
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        q.push({matrix[0][0], 0});
        visited[0][0] = 1;
        int count = 0;
        int res;

        while(count < k){
            int i = q.top().second / N;
            int j = q.top().second % N;
            int t = q.top().first;
            q.pop();
            count++;
            if(count == k)
                return t;
            
            if(i + 1 < M && j < N && visited[i + 1][j] == 0){
                q.push({matrix[i + 1][j], (i + 1)*N + j});
                visited[i + 1][j] = 1;
            }
            if(i < M && j + 1 < N && visited[i][j + 1] == 0){
                q.push({matrix[i][j + 1], i * N + j + 1});
                visited[i][j + 1] = 1;
            }
        }

        return res;
    }
};
// @lc code=end

