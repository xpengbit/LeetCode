/*
 * @lc app=leetcode id=403 lang=cpp
 *
 * [403] Frog Jump
 */

// @lc code=start
class Solution {
    unordered_set<int> stoneSet;
    unordered_set<string> failureSet;
public:
    bool canCross(vector<int>& stones) {
        for(int s : stones)
            stoneSet.insert(s);
        return dfs(stones.back(), 1, 1);    
    }

    bool dfs(int dest, int start, int k){
        if(start == dest) return true;
        if(stoneSet.find(start) == stoneSet.end()) return false;
        string str = to_string(start) + "-" + to_string(k);
        if(failureSet.find(str) != failureSet.end()) return false;

        for(int i = max(1, k - 1); i <= k + 1; ++i)
            if(dfs(dest, start + i, i)) return true;
        
        failureSet.insert(str);
        return false;
    }
};
// @lc code=end

