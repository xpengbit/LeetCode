/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);            
    }
private:
    int dfs(TreeNode* root, int sum){
        if(root == NULL) 0; 
        if(!root->left && !root->right) return 10*sum + root->val;
        return dfs(root->left, sum*10 + root->val) + dfs(root->right, sum * 10 + root->val);
    }
};
// @lc code=end

