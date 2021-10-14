/*
 * @lc app=leetcode id=1207 lang=cpp
 *
 * [1207] Unique Number of Occurrences
 */

// @lc code=start
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> numCnt;
        set<int> s;
        for(int num : arr) ++numCnt[num];
        for(auto n : numCnt){
            if(s.count(n.second)) return false;
            s.insert(n.second);
        }
        return true;
    }
};
// @lc code=end

