/*
 * @lc app=leetcode id=1644 lang=cpp
 *
 * [1644] Lowest Common Ancestor of a Binary Tree II
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
    int count = 0;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        TreeNode* lNode = dfs(root, p->val);
        TreeNode* rNode = dfs(root, q->val);
        return (lNode == NULL || rNode == NULL) ? NULL : lowestCommonAncestor(root, p, q);
    }
private:
    TreeNode* dfs(TreeNode* cur, int target){
        if(!cur) return NULL;
        if(cur->val == target) return cur;
        TreeNode* left = dfs(cur->left, target);
        TreeNode* right = dfs(cur->right, target);
        return left == NULL ? right : left;
    }

    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL || root == p || root == q) return root;
        TreeNode* l = lca(root->left, p, q);
        TreeNode* r = lca(root->right, p, q);
        if(l && r) return root;
        return l ? l : r;
    }

    TreeNode* lca2(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return NULL;
        TreeNode* l = lca2(root->left, p, q);
        TreeNode* r = lca2(root->right, p, q);
        if(root == p || root == q){
            count++;
            return root;
        }
        if(l && r) return root;
        return l ? l : r;
    }
};
// @lc code=end

