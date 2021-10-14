/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> m;
        for(string str : strs){
            string t = str;
            sort(t.begin(), t.end());
            if(!m.count(t)){
                m[t] = res.size();
                res.push_back({});
            }
            res[m[t]].push_back(str);
        }
        return res;

        /*
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for(string str : strs){
            string t = str;
            sort(t.begin(), t.end());
            m[t].push_back(str);
        }
        for(auto it : m){
            res.push_back(it.second);
        }
        return res;*/
    }
};
// @lc code=end

