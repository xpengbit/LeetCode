/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        vector<int> res;
        //preorder(root, res);
        //return res;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* cur = s.top(); s.pop();
            res.push_back(cur->val);
            if(cur->right) s.push(cur->right);
            if(cur->left) s.push(cur->left);
        }
        return res;

        /*模板2*/
        /*if(root == NULL) return {};
        vector<int> res;
        stack<int> st;
        TreeNode* cur = root;
        while(!st.empty() || cur){
            if(cur){
                st.push(cur);
                res.push_back(cur->val);
                cur = cur->left;
            }
            else{
                cur = st.top(); st.pop();
                cur = cur->right;
            }
        }
        return res;*/
    }
private:
    void preorder(TreeNode* root, vector<int>& res){
        if(root == NULL) return;
        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
    }
};
// @lc code=end

