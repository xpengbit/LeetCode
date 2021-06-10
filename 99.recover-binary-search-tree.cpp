/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
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
    TreeNode* pre = new TreeNode(INT_MIN);
    TreeNode* first = NULL, *second = NULL;
    void recoverTree(TreeNode* root) {
        in_order(root);
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }
private:
    void in_order(TreeNode* root){
        stack<TreeNode*> s;
        while(!s.empty() || root != NULL){
            while(root != NULL){
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if(first == NULL and root->val < pre->val) first = pre;
            if(first != NULL and root->val < pre->val) second = root;
            pre = root;
            root = root->right;
        }
    }
};
// @lc code=end

