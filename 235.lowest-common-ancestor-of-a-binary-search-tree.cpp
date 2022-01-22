/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /*iterative solution*/
        while(true){
            if(root->val < p->val and root->val < q->val) root = root->right;
            else if(root->val > p->val and root->val > q->val) root = root->left;
            else return root;
        }

        /*recursion solution*/
        /*if(root->val < p->val and root->val < q->val) return lowestCommonAncestor(root->right, p, q);
        else if(root->val > p->val and root->val > q->val) return lowestCommonAncestor(root->left, p, q);
        return root;*/
    }
};
// @lc code=end

