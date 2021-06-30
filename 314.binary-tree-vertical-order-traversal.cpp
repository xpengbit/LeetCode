
/*
 * @lc app=leetcode id=314 lang=cpp
 *
 * [314] Binary Tree Vertical Order Traversal
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
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        queue<pair<int, TreeNode*>> q;
        unordered_map<int, vector<int>> coltoNode;
        q.push({0, root});
        while(! q.empty()){
            auto cur = q.front();
            q.pop();
            coltoNode[cur.first].push_back(cur.second->val);
            if(cur.second->left) q.push({cur.first - 1, cur.second->left});
            if(cur.second->right) q.push({cur.first + 1, cur.second->right});
        }
        while(coltoNode.find(left_min) != end()) res.push_back(coltoNode[left_min++]);

        return res;            
        }    
    };

