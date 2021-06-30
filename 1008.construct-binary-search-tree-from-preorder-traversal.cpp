/*
 * @lc app=leetcode id=1008 lang=cpp
 *
 * [1008] Construct Binary Search Tree from Preorder Traversal
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int pos = 0;
        return helper(preorder, pos, INT_MAX);
    }
private:
    TreeNode* helper(vector<int>& preorder, int& pos, int bound){
        if(pos >= preorder.size() or preorder[pos] > bound) return nullptr;
        TreeNode* root = new TreeNode(preorder[pos]);
        pos++;
        root->left = helper(preorder, pos, root->val);
        root->right = helper(preorder, pos, bound);
        return root;
    }
};
// @lc code=end

