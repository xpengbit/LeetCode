/*
 * @lc app=leetcode id=690 lang=cpp
 *
 * [690] Employee Importance
 */

// @lc code=start
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int res = 0;
        unordered_map<int, pair<int, vector<int>>> mp;
        for(auto tmp : employees){
            mp[tmp->id] = {tmp->importance, tmp->subordinates};
        }
        res = dfs(mp, id);
        return res;    
    }
private:
    int dfs(unordered_map<int, pair<int, vector<int>>>& mp, int id){
        int sum = mp[id].first;
        if(mp[id].second.empty()){
                return mp[id].first;
            }
        else{
            for(int i : mp[id].second){
                sum += dfs(mp, i);
            }
        }
        return sum;
    }
};
// @lc code=end

