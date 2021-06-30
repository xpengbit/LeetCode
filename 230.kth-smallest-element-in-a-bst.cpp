/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    int res;
    int kthSmallest(TreeNode* root, int k) {
        return inTraversal(root, k);    
    }
private:
    int inTraversal(TreeNode* root, int& k) {
        if(!root) return 0;
        inTraversal(root->left, k);
        k--;
        if(k == 0){ 
            res = root->val;
            return res;
        }
        inTraversal(root->right, k);
        return res; 
    }
};
// @lc code=end

