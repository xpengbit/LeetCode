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
        int num = 0, sum = 0;
        helper(root, num, sum);
        return sum;            
    }
private:
    void helper(TreeNode* root, int num, int&sum){
        if(root == NULL) return; 
        num = 10*num + root->val;
        if(!root->left and !root->right) sum += num;
        helper(root->left, num, sum);
        helper(root->right, num, sum);
    }
};
// @lc code=end

