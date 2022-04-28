/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> Map;
        vector<int> res;
        int start = 0, last = 0;

        for(int i = 0; i < s.size(); ++i) Map[s[i]] = i;
        for(int i = 0; i < s.size(); ++i){
            last = max(last, Map[s[i]]);
            if(i == last){
                res.push_back(i - start + 1);
                start = i + 1;
            }
        }
        return res;    
    }
};
// @lc code=end

