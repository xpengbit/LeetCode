/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    vector<int> inorderTraversal(TreeNode* root) {
        /*Recursive Solution*/
        /*vector<int> res;
        if(root == NULL) return res;
        inorder(root, res);    
        return res;*/
        
        /*Iterative Solution 1*/
        /*if(!root) return {};
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(!st.empty() || cur){
            if(cur){
                st.push(cur);
                cur = cur->left;
            }
            else{
                cur = st.top(); st.pop();
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;*/
        
        /*Iterative Solution 2*/
        if(!root) return {};
        vector<int> res;
        stack<TreeNode*> st;
        while(!st.empty() || root){
            while(root){
                st.push(root);
                root = root->left;
            }
            root = st.top(); st.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
private:
    void inorder(TreeNode* root, vector<int>& res){
        if(root == NULL) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
};
// @lc code=end

