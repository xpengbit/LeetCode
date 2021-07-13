/*
 * @lc app=leetcode id=1123 lang=cpp
 *
 * [1123] Lowest Common Ancestor of Deepest Leaves
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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        /*if(!root) return nullptr;
        int lheight = height(root->left);
        int rheight = height(root->right); 
        if(lheight == rheight) return root;
        if(lheight > rheight) return lcaDeepestLeaves(root->left);
        else return lcaDeepestLeaves(root->right);*/

        /*Pure Recursion solution. O(n)*/
        Pair res = lcahelper(root, 0);
        return res.node;
    }
private:
    class Pair{
        public:
        TreeNode* node;
        int d;
        Pair(TreeNode* node, int d){
            this->node = node;
            this->d = d;
        }
    };

    Pair lcahelper(TreeNode* root, int d){
        if(!root) return Pair(0, d);
        Pair l = lcahelper(root->left, d + 1);
        Pair r = lcahelper(root->right, d + 1);
        if(l.d == r.d){
            return Pair(root, l.d);
        }
        else 
            return l.d > r.d ? l : r;
    }

    int height(TreeNode* root){
        if(!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
};
// @lc code=end

