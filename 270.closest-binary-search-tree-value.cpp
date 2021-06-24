
/*
 * @lc app=leetcode id=270 lang=cpp
 *
 * [270] Closest Binary Search Tree Value
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
 
 * Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.
 * Note:
 * Given target value is a floating point.
 * You are guaranteed to have only one unique value in the BST that is closest to the target.
 * Example:
 * Input: root = [4,2,5,1,3], target = 3.714286

    4
   / \
  2   5
 / \
1   3
 * Output: 4

 */

class Solution {
public:
    int res = 0;
    double min = DBL_MAX;
    int closestValue(TreeNode* root, double target) {
        dfs(root, target);
        return res;
    }
    void dfs(TreeNode* root, double target){
        if(!root) return;
        if(abs(root->val - target < min)){
            min = abs(root->val - target);
            res = root->val;
        }
        if(target < root->val) dfs(root->left, target);
        else dfs(root->right, target);
    }
};

