/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
    int ret = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        longestPathtoLeaf(root);
        return ret - 1;
    }
    int longestPathtoLeaf(TreeNode* root){
        if(root == NULL) return 0;
        int leftPath = longestPathtoLeaf(root->left);
        int rightPath = longestPathtoLeaf(root->right);
        ret = max(ret, leftPath + rightPath + 1);
        return max(leftPath, rightPath) + 1;
    }
};
// @lc code=end

