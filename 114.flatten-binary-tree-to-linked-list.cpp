/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
    void flatten(TreeNode* root) {
        postorder(root);
    }
private:
    TreeNode* postorder(TreeNode* root){
        if(!root) return NULL;
        //保留leftlast and rightlast
        TreeNode* leftlast = postorder(root->left);
        TreeNode* rightlast = postorder(root->right);
        //
        if(leftlast){
            //右孩子接到左边的后面
            leftlast->right = root->right;
            //左孩子成为root的右孩子
            root->right = root->left;
            //root左孩子置为NULL
            root->left = NULL;
        }
        //返回最后一个node用于下一次衔接
        if(rightlast) return rightlast;
        else if(leftlast) return leftlast;
        return root;
    }
};
// @lc code=end

