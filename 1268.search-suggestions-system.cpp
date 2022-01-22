/*
 * @lc app=leetcode id=1268 lang=cpp
 *
 * [1268] Search Suggestions System
 */

// @lc code=start
/*class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        //Binary Search
        vector<vector<string>> ret;
        sort(products.begin(), products.end());
        string query;
        auto it = products.begin();
        for(char c : searchWord){
            query += c;
            vector<string> out;
            it = lower_bound(it, products.end(), query);
            for(int i = 0; i < 3 && it + i < products.end(); ++i){
                string str = *(it + i);
                if(str.substr(0, query.size()) != query) break;
                out.push_back(str);
            }
            ret.push_back(out);
        }
        return ret;
    }
};*/
/*class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ret;
        sort(products.begin(), products.end());
        vector<string> suggested = products;
        for(int i = 0; i < searchWord.size(); ++i){
            vector<string> filter, out;
            for(string s : suggested){
                if(s[i] == searchWord[i] && i < s.size()){
                    filter.push_back(s); 
                }
            }
            for(int j = 0; j < 3 && j < filter.size(); ++j){
                out.push_back(filter[j]);
            }
            ret.push_back(out);
            suggested = filter;
        }
        return  ret;        
    }
};*/

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ret;
        for(string word : products){
            TrieNode* node = root;
            for(char c : word){
                if(!node->next[c - 'a'])
                    node->next[c - 'a'] = new TrieNode();
                node = node->next[c - 'a'];
            }
            node->word = word;
        }

        TrieNode* node = root;
        for(char c : searchWord){
            vector<string> out;
            if(node){
                node = node->next[c - 'a'];
                findSuggestion(node, out);
            }
            ret.push_back(out);
        }        
        return ret;
    }
private:
    struct TrieNode{
        string word;
        TrieNode* next[26];
    };

    TrieNode* root = new TrieNode();

    void findSuggestion(TrieNode* node, vector<string>& out){
        if(!node || out.size() >= 3) return;
        if(!node->word.empty()) out.push_back(node->word);
        for(char c = 'a'; c <= 'z'; ++c){
            if(node->next[c - 'a'])
                findSuggestion(node->next[c - 'a'], out);
        }
    }
};

// @lc code=end

