/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
    int max_val = INT_MIN;
    int maxPathSum(TreeNode* root) {
        helper(root);
        return max_val;
    }
private:
    int helper(TreeNode* root){
        if(root == NULL) return 0;
        int l = max(0, helper(root->left));
        int r = max(0, helper(root->right));
        
        max_val = max(max_val, root->val+l+r);
        return max(l,r) + root->val; 
    }
};
// @lc code=end

