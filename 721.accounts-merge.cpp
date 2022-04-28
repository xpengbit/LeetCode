/*
 * @lc app=leetcode id=721 lang=cpp
 *
 * [721] Accounts Merge
 */

// @lc code=start
class Solution {
    unordered_map<string, string> father;
    unordered_map<string, string> owner;
    unordered_map<string, set<string>> rets;
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for(auto& a : accounts){
            string name = a[0];
            string email0 = a[1];
            owner[email0] = name;
            if(father.find(email0) == father.end())
                father[email0] = email0;
            for(int i = 2; i < a.size(); ++i){
                string email = a[i];
                if(father.find(email) == father.end())
                    father[email] = email;
                if(findFather(email0) != findFather(email))
                    Union(email, email0);
                
                owner[email] = name;
            }
        }

        for(auto& f : father){
            string email = f.first;
            string rootemail = findFather(email);
            rets[rootemail].insert(email);
        }

        vector<vector<string>> ans;
        for(auto& r : rets){
            vector<string> tmp;
            string name = owner[r.first];
            tmp.push_back(name);

            for(auto& a : r.second)
                tmp.push_back(a);
            
            ans.push_back(tmp);
        }

        return ans;    
    }

    string findFather(string x){
        if(father[x] != x)
            father[x] = findFather(father[x]);

        return father[x];
    }

    void Union(string x, string y){
        x = father[x];
        y = father[y];

        if(x < y)
            father[y] = x;
        else
            father[x] = y;
    }

};
// @lc code=end

