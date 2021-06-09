/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
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
    int findBottomLeftValue(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> res;
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode* tmp = q.front();
                q.pop();
                if(i == 0) res.push_back(tmp->val);
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
        } 
        return res.back();
    }
};
// @lc code=end

