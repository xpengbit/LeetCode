/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret(nums1.size());
        stack<int> S;
        unordered_map<int, int> Map;
        for(int i = 0; i < nums2.size(); ++i){
            while(!S.empty() && nums2[S.top()] < nums2[i]){
                Map[nums2[S.top()]] = nums2[i];
                S.pop();
            }
            S.push(i);
        }
        
        for(int i = 0; i < nums1.size(); ++i){
            if(!Map.count(nums1[i]))
                ret[i] = -1;
            else
                ret[i] = Map[nums1[i]];
        }

        return ret;
    }
};
// @lc code=end

