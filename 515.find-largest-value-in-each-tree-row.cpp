/*
 * @lc app=leetcode id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            int max = INT_MIN;
            for(int i = 0; i < n; i++){
                TreeNode* tmp = q.front();
                q.pop();
                if(tmp->val > max) max = tmp->val;
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            res.push_back(max);
        }
        return res;
    }
};
// @lc code=end

