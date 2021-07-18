/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
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
    int rob(TreeNode* root) {
        /*vector<int> res = robHelper(root);
        return max(res[0], res[1]);*/
        int l = 0, r = 0;
        return helper(root, l, r);    
    }
private:
    int helper(TreeNode* root, int& l, int& r){
        if(!root) return 0;
        int ll = 0, lr = 0, rl = 0, rr = 0;
        l = helper(root->left, ll, lr);
        r = helper(root->right, rl, rr);
        return max(root->val + ll + lr + rl + rr, l + r);
    }

    vector<int> robHelper(TreeNode* root){
        if(root == NULL) return vector<int>(2, 0);
        /*0表示不抢，1表示抢*/
        vector<int> left = robHelper(root->left);
        vector<int> right = robHelper(root->right);
        vector<int> res(2, 0);
        res[1] = root->val + left[0] + right[0];
        res[0] = max(left[0], left[1]) + max(right[0], right[1]);
        return res;
    }
};
// @lc code=end

