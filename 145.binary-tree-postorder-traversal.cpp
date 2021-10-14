/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode* root) {
        /*if(root == NULL) return {};
        vector<int> res;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* cur = s.top();
            s.pop();
            res.insert(res.begin(), cur->val);
            if(cur->left) s.push(cur->left);
            if(cur->right) s.push(cur->right);
        }
        return res;*/
        //postorder(root, res);
        //return res;

        /*Iterative Solution 2*/
        if(!root) return {};
        stack<TreeNode*> st{{root}};
        TreeNode* pre = root;
        vector<int> res;
        while(!st.empty()){
            TreeNode* t = st.top();
            if((!t->left && !t->right) || t->left == pre || t->right == pre){
                res.push_back(t->val);
                st.pop();
                pre = t;
            }
            else{
                if(t->right) st.push(t->right);
                if(t->left) st.push(t->left);
            }
        }
        return res;   
    }
private:
    void postorder(TreeNode* root, vector<int>& res){
        if(root == NULL) return;
        postorder(root->left, res);
        postorder(root->right, res);
        res.push_back(root->val);
    }
};
// @lc code=end

