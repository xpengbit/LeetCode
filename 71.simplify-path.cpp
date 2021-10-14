/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> strs;
        int i = 0;
        while(i < path.size()){
            while(path[i] == '/' && i < path.size()) ++i;
            if(i == path.size()) break;
            int start = i;
            while(path[i] != '/' && i < path.size()) ++i;
            int end = i - 1;
            string tmp = path.substr(start, end - start + 1);
            if(tmp == ".."){
                if(!strs.empty()) strs.pop_back();
            }
            else if(tmp != "."){
                strs.push_back(tmp);
            }
        }
        if(strs.empty()) return "/";   
        string res;
        for(string str : strs){
            res += "/" + str;
        }
        return res;
    }
};
// @lc code=end

