/*
 * @lc app=leetcode id=819 lang=cpp
 *
 * [819] Most Common Word
 */

// @lc code=start
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string, int> strCnt;

        for(auto& c : paragraph) c = isalpha(c) ? tolower(c) : ' ';
        int mx = 0;
        string res = "", t = "";
        istringstream iss(paragraph);
        while(iss >> t){
            if(!ban.count(t) && ++strCnt[t] > mx){
                mx = strCnt[t];
                res = t;
            }
        }
        return res;
    }
};
// @lc code=end

