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
        if(deepth(root) == -1)
            return false;
        else
            return true;
    }
private:
    int deepth(TreeNode* root){
        if(root == NULL) return 0;
        int dl = deepth(root->left);
        int dr = deepth(root->right);
        if(dl == -1 || dr == -1 || abs(dl - dr) > 1)
            return -1;
        else
            return max(dl, dr) + 1;
    }
};
// @lc code=end

