/*
 * @lc app=leetcode id=865 lang=cpp
 *
 * [865] Smallest Subtree with all the Deepest Nodes
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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        /*if(root == nullptr) return nullptr;
        int ldeep = deep(root->left);
        int rdeep = deep(root->right);
        if(ldeep == rdeep) return root;
        if(ldeep > rdeep) return subtreeWithAllDeepest(root->left);
        else return subtreeWithAllDeepest(root->right);*/
        Pair res = helper(root, 0);
        return res.node;
    }

private:
    class Pair{
        public:
            TreeNode* node;
            int d; /*deepth of the node*/
            Pair(TreeNode* node, int d){
                this->node = node;
                this->d = d;
            }
    };

    Pair helper(TreeNode* root, int d){
        if(!root) return Pair(0, d);
        Pair l = helper(root->left, d + 1);
        Pair r = helper(root->right, d + 1);
        if(l.d == r.d) return Pair(root, l.d);
        return l.d > r.d ? l : r;
    }
    int deep(TreeNode* root){
        if(!root) return 0;
        return 1 + max(deep(root->left), deep(root->right));
    }
};
// @lc code=end

