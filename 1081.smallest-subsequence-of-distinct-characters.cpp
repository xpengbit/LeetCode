/*
 * @lc app=leetcode id=1081 lang=cpp
 *
 * [1081] Smallest Subsequence of Distinct Characters
 */

// @lc code=start
class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char, int> Map;
        for(char c : s)
            Map[c]++;
        vector<int> visited(256);
        string str;
        for(char c : s){
            if(visited[c]){
                Map[c]--;
                continue;
            }
            else{
                while(!str.empty() && str.back() > c && Map[str.back()] > 0){
                    visited[str.back()] = 0;
                    str.pop_back();
                }
                str.push_back(c);
                Map[c]--;
                visited[c] = 1;
            }
        }
        return str;
    }
};
// @lc code=end
//维护一个递增序列。如果新来的c已经用过，则continue;
//如果新来的c大于str最后一个字母，则看最后一个字母count是否>0, 如果还有。则弹出。
