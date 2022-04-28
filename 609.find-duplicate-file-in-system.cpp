/*
 * @lc app=leetcode id=609 lang=cpp
 *
 * [609] Find Duplicate File in System
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> Map;

        for(string p : paths){
            istringstream is(p);
            string pre = "", t = "";
            is >> pre;
            while(is >> t){
                int indx = t.find_first_of('(');
                string dir = pre + "/" + t.substr(0, indx);
                string content = t.substr(indx + 1, t.size() - indx - 2);
                Map[content].push_back(dir);
            }
        }
        for(auto m : Map){
            if(m.second.size() > 1)
                res.push_back(m.second);
        }

        return res;
    }
};
// @lc code=end

//这个题要学会istringstream 的使用。 >> 到第一个空格处。

