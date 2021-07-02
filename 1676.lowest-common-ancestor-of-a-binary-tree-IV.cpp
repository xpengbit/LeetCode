/*
 * @lc app=leetcode id=1676 lang=cpp
 *
 * [1676] Lowest Common Ancestor of a Binary Tree IV
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
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> nodes) {
        if(!root) return NULL;
        set<TreeNode*> nodeSet;
        for(TreeNode* t : nodes) nodeSet.insert(t);
        return lcaHelper(root, nodeSet);
    }
private:
    TreeNode* lcaHelper(TreeNode* root, set<TreeNode*> nodeSet){
        if(!root) return NULL;
        if(nodeSet.count(root->val)) return root;
        TreeNode* l = lcaHelper(root->left, nodeSet);
        TreeNode* r = lcaHelper(root->right, nodeSet);
        if(l && r) return root;
        return l ? l : r;
    }
};
// @lc code=end

