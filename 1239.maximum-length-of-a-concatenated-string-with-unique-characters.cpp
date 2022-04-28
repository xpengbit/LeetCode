/*
 * @lc app=leetcode id=1239 lang=cpp
 *
 * [1239] Maximum Length of a Concatenated String with Unique Characters
 */

// @lc code=start
class Solution {
    int res = 0;
public:
    int maxLength(vector<string>& arr) {
        dfs(arr, 0, "");
        return res;    
    }
private:
    void dfs(vector<string>& arr, int index, string tmp){
        if(index == arr.size()){
            if(isValid(tmp) && res < tmp.length())
                res = tmp.length();
            return;
        }

        dfs(arr, index + 1, tmp);
        if(tmp.size() + arr[index].size() <= 26)
            dfs(arr, index + 1, tmp + arr[index]);
    }

    bool isValid(string s){
        int cnt[26] = {0};
        for(char c : s){
            if(cnt[c - 'a']++ > 0)
                return false;
        }
        return true;
    }
};
// @lc code=end

