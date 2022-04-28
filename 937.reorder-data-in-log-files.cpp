/*
 * @lc app=leetcode id=937 lang=cpp
 *
 * [937] Reorder Data in Log Files
 */

// @lc code=start
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> res, digitLog;
        vector<vector<string>> letterLog;

        for(string log : logs){
            auto pos = log.find(" ");
            if(log[pos + 1] >= '0' && log[pos + 1] <= '9'){
                digitLog.push_back(log);
                continue;
            }
            letterLog.push_back({log.substr(0, pos), log.substr(pos + 1)});
        }

        sort(letterLog.begin(), letterLog.end(), [](vector<string> & a, vector<string>& b){
            return a[1] < b[1] || (a[1] == b[1] && a[0] < b[0]);
        });

        for(auto& l : letterLog){
            res.push_back(l[0] + " " + l[1]);
        }

        for(auto& d : digitLog){
            res.push_back(d);
        }

        return res;    
    }
};
// @lc code=end

