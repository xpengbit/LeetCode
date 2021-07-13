/*
 * @lc app=leetcode id=1120 lang=cpp
 *
 * [1120] Maximum Average Subtree
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
    double maxAvg;
    double maximumAverageSubtree(TreeNode* root) {
        maxAvg = 0.0;
        helper(root);
        return maxAvg;
    }
private:
    vector<int> helper(TreeNode* root){
        if(root == NULL) return vector<int>(2, 0);
        vector<int> res = new vector<int>)(2, 0);
        vector<int> l = helper(root->left);
        vector<int> r = helper(root->right);
        res[0] = root->val + l[0] + r[0]; //sum
        res[1] = (1 + l[1] + r[1]);   //count
        
        maxAvg = max(maxAvg, (double)res[0]/(double)res[1]);
        return res; 
    }
};
// @lc code=end

