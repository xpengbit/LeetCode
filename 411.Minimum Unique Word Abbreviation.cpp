/*
 * @lc app=leetcode id=411 lang=cpp
 *
 * [411] Minimum Unique Word Abbreviation
 */

// @lc code=start
class Solution {
    int m;
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        if(dictionary.size() == 0) return to_string(target.size()).len();

        this->m = target.size();
        vector<pair<int, int>> masks;
        unordered_set<string> Set;

        for(string word : dictionary)
            if(word.size() == m) Set.insert(word); //只有原本相同长度的缩写以后才有可能相等

        for(int state = 0; state < (1 << m); ++state){
            masks.push_back({len(state), state});   
        }
        sort(masks.begin(), masks.end());

        for(auto m : masks){
            int mask = m.second;
            string abbr = getAbbrFromMask(target, mask);
            int flag = 1;
            for(string s : Set){
                string tmp = getAbbrFromMask(s, mask);
                if(abbr == tmp){
                    flag = 0;
                    break;
                }
            }
            if(flag == 1) return abbr;
        }
        
        return "";
    }
    
    string getAbbrFromMask(string target, int mask){
        string res = "";
        for(int i = 0; i < m; ++i){
            if((mask >> i) & 1 == 1) res += target[i]; 
            else{
                int j = i;
                while(j < m && (mask >> j) & 1 == 0) ++j;
                res += to_string(j - i);
                i = j - 1;
            }
        }
        return res;
    }

    int len(int mask){
        int count = 0;
        for(int i = 0; i < m; ++i){
            if((mask >> i)& 1 == 1)
                count++;
            else{
                int j = i;
                while(j < m && (mask >> j) & 1 == 0) ++j; //由j来统计0的个数
                count += to_string(j - i).size(); //这里是to_string后的长度
                i = j - 1; // j 已经走到1那一位，i退回来，再++
            }
        }
        return count;
    }
};
// @lc code=end