#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        int n = dict.size();
        vector<int> stillLeft(n);
        vector<string> res(n);
        for(int i = 0; i < n; ++i)
            stillLeft.push_back(i);
        
        int level = 0;
        while(1){
            unordered_map<string, vector<int>> mp;
            for(int i = 0; i < stillLeft.size(); ++i){
                string tmp = getAbbre(dict[i], level);
                mp[tmp].push_back(i);
            }
            stillLeft.clear();
            for(auto [s, index] : mp){
                if(index.size() > 1){
                    for(int ind : index)
                        stillLeft.push_back(ind);
                }
                else
                    res[index[0]] = s;            
            }

            level++;
            if(stillLeft.size() == 0)
                break;
        }
        return res;
    }
    string getAbbre(string s, int k) {
        if(s.size() < 3) return s;
        string t;
        t += s.substr(0, k);
        t += to_string(s.size() - k - 1);
        t += s.back();

        if(t.size() == s.size()) return s;

        return t;
    }
};