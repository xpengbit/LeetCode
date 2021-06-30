/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if(n == 0) return res;
        return helper(1, n);
    }
private:
    vector<TreeNode*> helper(int start, int end){
        vector<TreeNode*> res;
        if(start > end) res.push_back(NULL);
        for(int i = start; i <=end; i++){
            //cout <<"i=" << i;
            vector<TreeNode*> leftlist = helper(start, i - 1);
            vector<TreeNode*> rightlist = helper(i + 1, end);
            for(TreeNode* left : leftlist){
                for(TreeNode* right : rightlist){
                    TreeNode * root = new TreeNode(i);
                    //cout << "root->val=" << root->val << endl;
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
// @lc code=end

