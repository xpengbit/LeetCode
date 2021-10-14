/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 */

// @lc code=start
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        /*moor 投票法*/
        vector<int> res;
        int cnt1 = 0, cnt2 = 0, a = 0, b = 0, n = nums.size();
        for(int num : nums){
            if(num == a) cnt1++;
            else if(num == b) cnt2++;
            else if(cnt1 == 0) {a = num; cnt1 = 1;}
            else if(cnt2 == 0) {b = num; cnt2 = 1;}
            else{
                cnt1--; cnt2--;
            }
        }
        cnt1 = cnt2 = 0;
        for(int num : nums){
            if(num == a) ++cnt1;
            else if(num == b) ++cnt2;
        }
        if(cnt1 > n / 3) res.push_back(a);
        if(cnt2 > n / 3) res.push_back(b);
        
        return res;
    }
};
// @lc code=end

