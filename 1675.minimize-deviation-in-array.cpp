/*
 * @lc app=leetcode id=1675 lang=cpp
 *
 * [1675] Minimize Deviation in Array
 */

// @lc code=start
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        multiset<int> Set;
        for(auto x : nums){
            if(x % 2 == 0) Set.insert(x);
            else Set.insert(x * 2);
        }

        int ret = INT_MAX;
        while(!Set.empty()){
            ret = min(ret, *Set.rbegin() - *Set.begin());
            int k = *Set.rbegin();
            if(k % 2 != 0)
                break;
            Set.erase(prev(Set.end()));
            Set.insert(k / 2);
        }
        return ret;
    }
};
// @lc code=end

