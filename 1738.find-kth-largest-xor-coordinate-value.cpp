/*
 * @lc app=leetcode id=1738 lang=cpp
 *
 * [1738] Find Kth Largest XOR Coordinate Value
 */

// @lc code=start

//两种解法，一种PQ, 一种二分搜值;
class Solution {
    int pre[1000][1000];
    int m, n;
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        m = matrix.size();
        n = matrix[0].size();
        
        pre[0][0] = matrix[0][0];
        for(int i = 1; i < m; ++i)
            pre[i][0] = pre[i - 1][0] ^ matrix[i][0];
        for(int j = 1; j < n; ++j)
            pre[0][j] = pre[0][j - 1] ^ matrix[0][j];

        for(int i = 1; i < m; ++i)
            for(int j = 1; j < n; ++j)
                pre[i][j] = pre[i - 1][j] ^ pre[i][j - 1] ^ matrix[i][j] ^ pre[i - 1][j - 1];
        
        //PQ
        /*priority_queue<int, vector<int>, greater<>> pq;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j){
                pq.push(pre[i][j]);
                if(pq.size() > k)
                    pq.pop();
            }

        return pq.top();*/

        //Bianry Search
        int left = 0, right = INT_MAX;
        while(left < right){
            int mid = right - (right - left) / 2;
            if(countK(mid) < k) //countK 返回 >= mid 的个数
                right = mid - 1;
            else
                left = mid;
        }
        return left;   
    }

    int countK(int val){
        int ret = 0;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(pre[i][j] >= val)
                    ++ret;
        
        return ret;
    }
};
// @lc code=end

