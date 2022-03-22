/*
 * @lc app=leetcode id=517 lang=cpp
 *
 * [517] Super Washing Machines
 */

// @lc code=start
class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int sum = accumulate(machines.begin(), machines.end(), 0);
        if(sum % machines.size() != 0) return -1;
        int ave = sum / machines.size();
        int cnt = 0, ret = 0;
        for(int x : machines){
            cnt += x - ave;
            ret = max(ret, max(abs(cnt), x - ave));
        }
        return ret;
    }
};
// @lc code=end

