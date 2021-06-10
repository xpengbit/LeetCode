/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int m = 0;
        return helper(preorder, inorder, 0, n, m);
    }
private:
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int l, int r, int& prestart){
        if(l >= r or prestart >= preorder.size()) return NULL;
        int index = 0;
        int root_val = preorder[prestart];
        for(int i = l; i < r; i++){
            if(inorder[i] == preorder[prestart]){
                index = i;
                break;
            }
        }
        TreeNode* root = new TreeNode(root_val);
        prestart++;
        root->left = helper(preorder, inorder, l, index, prestart);
        root->right = helper(preorder, inorder, index+1, r, prestart);
        return root;
    }
};
// @lc code=end

