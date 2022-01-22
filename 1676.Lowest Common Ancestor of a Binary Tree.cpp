/*
 * @lc app=leetcode id=1676 lang=cpp
 *
 * [1676] Lowest Common Ancestor of a Binary Tree
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
    TreeNode* ret = NULL;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*>& nodes) {
        unordered_set<TreeNode*>Set;
        for(auto n : nodes)
            Set.insert(n);
        int a = dfs(root, Set);
        return ret;
    }
private:
    int dfs(TreeNode* root, unordered_set<TreeNode*>& nodes){
        if(root == NULL) return -1;
        if(ret != NULL) return -1;
        int count = dfs(root->left, nodes) + dfs(root->right, nodes) + (nodes.find(root) != nodes.end());
        if( count == nodes.size() && ret == NULL)
            ret = root;
        return count; 
    }
};
// @lc code=end

