/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
    int countNodes(TreeNode* root) {
        int left = leftHeight(root);
        int right = rightHeight(root);
        
        if(left == right) 
            return (1 << left) - 1;
        else
            return 1 + countNodes(root->left) + countNodes(root->right);    
    }
private:
    int leftHeight(TreeNode* root){
        int res = 0;
        while(root != 0){
            res++;
            root = root->left;
        }
        return res;
    }
    int rightHeight(TreeNode* root){
        int res = 0;
        while(root){
            res++;
            root = root->right;
        }
        return res;
    }
};
// @lc code=end

