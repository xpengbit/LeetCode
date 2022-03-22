/*
 * @lc app=leetcode id=68 lang=cpp
 *
 * [68] Text Justification
 */

// @lc code=start
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        for(int i = 0; i < words.size(); ++i){
            int j = i, count = 0;
            while(j < words.size() && count <= maxWidth){
                if(count == 0)
                    count += words[j].size();
                else
                    count += 1 + words[j].size();
                j++;
            }
            j--;
            if(count > maxWidth)
                j--;
            if(j == words.size() - 1){
                string tmp;
                for(int k = i; k <= j; ++k)
                    tmp += words[k] + " ";
                tmp.pop_back();
                tmp += addSpace(maxWidth - tmp.size());
                ret.push_back(tmp);
            }
            else
                ret.push_back(printLine(words, i, j, maxWidth));
            
            i = j;
        }
        return ret;
    }

    string printLine(vector<string>& words, int a, int b, int maxWidth){
        if(a == b)
            return words[a] + addSpace(maxWidth - words[a].size());
        
        int letterLen = 0;
        for(int i = a; i <= b; ++i)
            letterLen += words[i].size();
        int space = (maxWidth - letterLen) / (b - a) ;
        int k = maxWidth - letterLen - space * (b - a);

        string ret;
        for(int i = a; i < a + k; ++i)
            ret += words[i] + addSpace(space + 1);
        for(int i = a + k; i < b; ++i)
            ret += words[i] + addSpace(space);
        ret += words[b];

        return ret;    
    }

    string addSpace(int k){
        string ret;
        for(int i = 0; i < k; ++i)
            ret += " ";
        return ret;
    }
};
// @lc code=end

