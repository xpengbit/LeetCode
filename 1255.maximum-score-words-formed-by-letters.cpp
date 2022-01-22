/*
 * @lc app=leetcode id=1255 lang=cpp
 *
 * [1255] Maximum Score Words Formed by Letters
 */

// @lc code=start
/*class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> cnt(26);
        for(char c : letters) cnt[c - 'a']++;
        return dfs(words, cnt, score, 0);    
    }

    int dfs(vector<string>& words, vector<int>& cnt, vector<int>& score, int index){
        int res = 0;
        for(int i = index; i < words.size(); ++i){
            int sum = 0, isValid = 1;
            for(char c : words[i]){
                if(--cnt[c - 'a'] < 0)
                    isValid = 0;
                sum += score[c - 'a'];
            }
            if(isValid){
                sum += dfs(words, cnt, score, index + 1);
                res = max(res, sum);
            }
            for(char c : words[i])
                ++cnt[c - 'a'];
        }
        return res;
    }
};*/

class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int res = 0, n = words.size(), m = 1 << n;
        vector<int> cnt(26);
        for(char c : letters) ++cnt[c - 'a'];

        for(int mask = 0; mask < m; ++mask){
            int sum = 0, isValid = 1;
            vector<int> count = cnt;
            for(int i = n - 1; i >= 0; --i){
                if(mask >> i & 1){
                    for(char c : words[i]){
                        if(--count[c - 'a'] < 0){
                            isValid = 0;
                            break;
                        }
                        sum += score[c - 'a'];
                    }
                }
                if(!isValid) break;
            }
            if(isValid) res = max(res, sum);
        }
        return res;
    }
};
// @lc code=end

