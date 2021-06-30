/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(res, root, path, targetSum);
        return res;
    }
private:
    void dfs(vector<vector<int>>& res, TreeNode* root, vector<int>& path, int targetSum){
        if(root == NULL)
            return;
        path.push_back(root->val);
        if(root->left == NULL and root->right == NULL and root->val == targetSum){
            res.push_back(path);
        }
        dfs(res, root->left, path, targetSum - root->val);
        dfs(res, root->right, path, targetSum - root->val);
        path.pop_back();
    }
};
// @lc code=end

