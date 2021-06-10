/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int m = postorder.size()-1;
        return helper(inorder, postorder, 0, n, m);
    }
private:
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int l, int r, int& poststart){
        if(l >= r or poststart < 0) return NULL;
        int root_val = postorder[poststart];
        cout << root_val << endl;
        int index = 0;
        for(int i = l; i < r; i++){
            if(inorder[i] == root_val){
                index = i;
                break;
            }
        }
        
        TreeNode* root = new TreeNode(root_val);
        poststart--;
        root->right = helper(inorder, postorder, index+1, r, poststart);
        root->left = helper(inorder, postorder, l, index, poststart);
        return root;
    }
};
// @lc code=end

