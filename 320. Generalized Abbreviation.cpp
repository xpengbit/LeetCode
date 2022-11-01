/*[LeetCode] 320. Generalized Abbreviation 通用简写
Write a function to generate the generalized abbreviations of a word. 
Note: The order of the output does not matter.
Example:
Input: 
"word"
Output:
["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1","3d", "w3", "4"]
*/

class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        int n = word.size();

        for(int state = 0; state < (1 << n); ++state){
            string s;
            for(int i = 0; i < n; ++i){
                if((state >> i) & 1){
                    int j = i;
                    while(j < n && ((state >> j) & 1))
                        j++;
                    s += to_string(j - i);
                    i = j - 1;
                }
                else{
                    s.push_back(word[i]);
                }
            }
            res.push_back(s);
        } 
        return res; 
    }
};