/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        helper(root, "", res);
        return res;
    }
private:
    void helper(TreeNode* root, string path, vector<string>& res){
        if(root == NULL) return;
        if(!root->left and !root->right) res.push_back(path + to_string(root->val));
        helper(root->left, path + to_string(root->val) + "->", res);
        helper(root->right, path + to_string(root->val) + "->", res);        
    }
};
// @lc code=end

