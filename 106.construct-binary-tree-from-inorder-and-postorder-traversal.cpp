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
    vector<int> inorder, postorder;
    int postorderIndex;
    map<int, int> inorderMap;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        /*int n = inorder.size();
        int m = postorder.size()-1;
        return helper(inorder, postorder, 0, n, m);*/
        this->inorder = inorder;
        this->postorder = postorder;
        int n = inorder.size();
        postorderIndex = n - 1;
        for(int i = 0; i < n; i++) inorderMap[inorder[i]] = i;
        return helper2(0, n - 1);
    }
private:
    TreeNode* helper2(int inorderStart, int inorderEnd){
        if(inorderStart > inorderEnd) return nullptr;
        TreeNode* root = new TreeNode(postorder[postorderIndex--]);
        int index = inorderMap[root->val];
        root->right = helper2(index + 1, inorderEnd);
        root->left = helper2(inorderStart, index - 1);
        return root;
    }

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

