/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        //BFS+PQ O(3nlog3n)
        /*priority_queue<long long, vector<long long>, greater<>> pq;
        pq.push(1);
        for(int i = 0; i < n; ++i){
            long long cur = pq.top();
            pq.pop();
            if(i == n - 1) return cur;
            while(!pq.empty() && cur == pq.top())
                pq.pop();
            pq.push(cur*2);
            pq.push(cur*3);
            pq.push(cur*5);
        }
        return -1;*/

        //kind of DP solution
        int i = 0, j = 0, k = 0;
        vector<int> res({1});
        while(res.size() < n){
            int cur = min(res[i] * 2, min(res[j] * 3, res[k] * 5));
            res.push_back(cur);
            if(cur == res[i]*2) i++;
            if(cur == res[j]*3) j++;
            if(cur == res[k]*5) k++;
        }
        return res.back();
    }
};
// @lc code=end

