/*
 * @lc app=leetcode id=687 lang=cpp
 *
 * [687] Longest Univalue Path
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
    int res = 0;
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return max(0, res - 1);
    }

    int dfs(TreeNode* root){
        if(root == NULL) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);

        int L = 0, R = 0;
        if(root->left && root->left->val == root->val)
            L = left;
        if(root->right && root->right->val == root->val)
            R = right;
        
        res = max(res, L + R + 1);
        return max(L, R) + 1;
    }
};
// @lc code=end

