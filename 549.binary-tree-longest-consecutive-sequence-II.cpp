/*
 * @lc app=leetcode id=549 lang=cpp
 *
 * [549] Binary Tree Longest Consecutive Sequence II
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
    int longestConsecutive(TreeNode* root) {
        helper(root);
        return max_val;
    }
private:
    vector<int> helper(TreeNode* root){
        if(!root) return {0, 0};
        vector<int> res(2, 0);
        int inc = 1, dcr = 1;
        if(root->left){
            vector<int> l = helper(root->left);
            if(root->val == root->left->val + 1) dcr = l[1] + 1;
            else if(root->val == root->left->val - 1) inc = l[0] + 1;
        }
        if(root->right){
            vecrot<int> r = helper(root->right);
            if(root->val == root->right->val + 1) dcr = max(r[1] + 1, dcr);
            else if(root->val == root->right->val - 1) inc = max(r[0] + 1, inc);

            max_val = max(max_val, inc + dcr - 1);
            return {inc, dcr}; 
        }
        vector<int> r = helper(root->right);
    }
};
// @lc code=end

