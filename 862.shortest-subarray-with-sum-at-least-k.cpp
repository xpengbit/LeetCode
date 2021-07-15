/*
 * @lc app=leetcode id=862 lang=cpp
 *
 * [862] Shortest Subarray with Sum at Least K
 */

// @lc code=start
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        /*Solution 1: the priority queue*/
        /*int n = nums.size(), res = INT_MAX, sum = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(sum >= k) res = min(res, i + 1);
            while(!pq.empty() && sum - pq.top().first >= k){
                res = min(res, i - pq.top().second);
                pq.pop();
            }
            pq.push({sum, i});
        }
        return res == INT_MAX ? -1 : res;*/

        /*Solution 2: prefixSum + dq */
        int n = nums.size(), res = INT_MAX;
        deque<int> dq;
        vector<int> sum(n + 1);
        for(int i = 0; i < n; i++) sum[i + 1] = sum[i] + nums[i];
        for(int i = 0; i <= n; i++){
            while(!dq.empty() && sum[i] - sum[dq.front()] >= k){
                res = min(res, i - dq.front());
                dq.pop_front();
            }
            while(!dq.empty() && sum[i] <= sum[dq.back()]) dq.pop_back(); //保证一个递增的队列
            dq.push_back(i);
        }
        return res == INT_MAX ? -1 : res;
    }
};
// @lc code=end

