/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        /*vector<int> res;
        multiset<int> Set;
        int left = 0;
        for(int i = 0; i < nums.size(); ++i){
            Set.insert(nums[i]);
            if(i - left + 1 == k){
                res.push_back(*Set.rbegin());
                Set.erase(Set.find(nums[left]));
                left++;
            }
        }
        return res;*/

        //解法2
        deque<int> dq;
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i){
            if(!dq.empty() && dq.front() == i - k) dq.pop_front();
            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
            if(i >= k - 1)
                res.push_back(nums[dq.front()]);
        }
        return res;    
    }
};
// @lc code=end

