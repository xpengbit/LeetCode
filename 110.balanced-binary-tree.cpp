/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int lh = deepth(root->left);
        int rh = deepth(root->right);
        return abs(lh-rh) <= 1 and isBalanced(root->left) and isBalanced(root->right);       
    }
private:
    int deepth(TreeNode* root){
        if(root == NULL) return 0;
        int dl = deepth(root->left);
        int dr = deepth(root->right);

        int deep = max(dl, dr) + 1;
        return deep;
    }
};
// @lc code=end

