/*
 * @lc app=leetcode id=1382 lang=cpp
 *
 * [1382] Balance a Binary Search Tree
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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> res;
        dfs(root, res);
        return build(0, res.size() - 1, res);
    }
private:
    void dfs(TreeNode* root, vector<int>& res){
        if(root == NULL) return;
        dfs(root->left, res);
        res.push_back(root->val);
        dfs(root->right, res);
    }

    TreeNode* build(int low, int high, vector<int> res){
        if(low > high) return NULL;
        int mid = low + (high - low)/2;
        TreeNode* root = new TreeNode(res[mid]);
        root->left = build(low, mid - 1, res);
        root->right = build(mid + 1, high, res);
        return root;
    }
};
// @lc code=end

