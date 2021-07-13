/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
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
    map<TreeNode*, TreeNode*> parentMap;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /*if(root == NULL || root == p || root == q) return root;
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        if(l && r) return root;
        return l ? l : r;*/
        if(!root) return NULL;
        dfs(0, root);
        set<TreeNode*> parentSet;
        while(p){
            parentSet.insert(p);
            p = parentMap[p];
        }

        while(parentSet.insert(q).second) q = parentMap[q];

        return q;
    }
private:
    void dfs(TreeNode* parentNode, TreeNode* cur){
        if(!cur) return;
        parentMap[cur] = parentNode;
        dfs(cur, cur->left);
        dfs(cur, cur->right);
    }
};
// @lc code=end

