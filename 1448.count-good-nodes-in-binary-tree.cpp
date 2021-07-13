/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
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
    int goodNodes(TreeNode* root) {
        dfs(root, INT_MIN);
        return res;
    }
private:
    void dfs(TreeNode* root, int maxPathVal){
        if(!root) return;
        if(root->val >= maxPathVal) res++;
        dfs(root->left, max(maxPathVal, root->val));
        dfs(root->right, max(maxPathVal, root->val));
    }
};
// @lc code=end

