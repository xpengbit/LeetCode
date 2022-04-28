#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>

using namespace std;

class solution{
public:
    vector<vector<string>> groupAnagram(vector<string>& strs){
        unordered_map<string, vector<string>> Map;
        for(string s : strs){
            string key = s;
            sort(key.begin(), key.end());
            Map[key].push_back(s);
        }

        vector<vector<string>> res;
        for(auto iter : Map){
            res.push_back(iter.second);
        }
        
        return res;
    }
};

int main(int arge, char* argv[]){
    solution testSolution;
    
    vector<string> str = {"eat", "ate", "tea", "tan", "nat", "bat"};
    vector<vector<string>> res;
    res = testSolution.groupAnagram(str);
    
    for(auto it : res){
        for(auto str : it){
            cout << str << " "; 
        }
        cout << endl;
    }

    return 0;
}