/*
 * @lc app=leetcode id=1650 lang=cpp
 *
 * [1650] Lowest Common Ancestor of a Binary Tree III
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode *parent;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        set<TreeNode*> parentNode;
        while(p && q){
            if(p != NULL && !parentNode.insert(p).second) return p;
            if(q != NULL && !parentNode.insert(q).second) return q;
            p = p->parent;
            q = q->parent;
        }
    }
}