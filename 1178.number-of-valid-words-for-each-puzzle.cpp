/*
 * @lc app=leetcode id=1178 lang=cpp
 *
 * [1178] Number of Valid Words for Each Puzzle
 */

// @lc code=start
class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        vector<int> res;
        unordered_map<int, int> mp;
        for(string word : words){
            int mask = 0;
            for(char c : word){
                mask |= 1 << (c - 'a');
            }
            ++mp[mask];
        }

        for(string puzzle : puzzles){
            int mask = 0;
            for(char c : puzzle){
                mask |= 1 << (c - 'a');
            }
            int head = 1 << (puzzle[0] - 'a'), cnt = 0, sub = mask;
            while(true){
                if(sub == 0) break;
                if((sub & head) == head && mp.count(sub))
                    cnt += mp[sub];
                sub = (sub - 1) & mask;
            }
            res.push_back(cnt);
        }
        return res;
    }
};
// @lc code=end

