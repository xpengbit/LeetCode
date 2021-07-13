/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */

// @lc code=start
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<int>> dp = vector<vector<int>>(s.length() + 1, vector<int>(s.length()));
        unordered_set<string> dict;
        dict = unordered_set<string>(dict.cbegin(), dict.cend());
        dp[0].push_back(0);
        for(int i = 1; i <= s.length(); i++){
            for(int j = 0; j < i; j++){
                if(!dp[j].empty() && dict.count(s.substr(j, i - j)))
                    dp[i].push_back(j);
            }
        }

        for(int i = 0; i<= s.length(); i++){
            for(int j = 0; j < s.length(); j++){
                cout << dp[i][j] <<",";
            }
            cout << endl;
        }
        getResult(s, dp, "", s.length());
        return res;
    }
private:
    vector<string> res;

    void getResult(string s, vector<vector<int>> dp, string cur, int index){
        if(index == 0){ 
            res.push_back(cur);
            return;
        }
        for(int preIndex : dp[index])
            getResult(s, dp, s.substr(preIndex, index - preIndex) + " " + cur, preIndex);
    }
};
// @lc code=end

