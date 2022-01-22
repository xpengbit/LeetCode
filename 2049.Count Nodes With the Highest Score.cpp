/*
 * @lc app=leetcode id=2049 lang=cpp
 *
 * [2049] Diameter of Binary TreeCount Nodes With the Highest Score
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
    using LL = long long; 
    vector<vector<int>> children;
    unordered_map<LL, int> Map;
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        for(int i = 1; i < n; ++i){
            children[parents[i]].push_back(i);
        }

        dfs(0);
        LL key = INT_MIN;
        int count = 0;
        for(auto x : Map){
            if(x.first > key){
                key = x.first;
                count = x.second;
            }
        }

        return count; 
    }
    
    int dfs(int node){ //the number of nodes in the subtree rooted as node
        int n = children.size();
        vector<int> sub;
        LL sub_total = 0;
        
        for(int child : children[node]){
            sub.push_back(dfs(child));
            sub_total += sub.back();
        }

        LL score = 1;
        if(n - 1 - sub_total > 0) 
            score *= n - 1 - sub_total;
        for(int num : sub)
            if(num > 0)  score *= num;
        
        Map[score] += 1;
        
        return sub_total + 1; 
    }
};