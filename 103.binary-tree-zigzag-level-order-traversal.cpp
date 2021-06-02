/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;

        queue<TreeNode*> q;
        q.push(root);
        int step = 0;
        while(!q.empty()){
            int n = q.size();
            vector<int> vi;
            for(int i = 0; i < n; i++){
                TreeNode* tmp = q.front();
                q.pop();
                if(step % 2 == 0)
                    vi.push_back(tmp->val);
                else
                    vi.insert(vi.begin(), tmp->val);
                if(tmp->left != NULL) q.push(tmp->left);
                if(tmp->right != NULL) q.push(tmp->right);
            }
            step++;
            res.push_back(vi);
        }
        return res;
    }
};
// @lc code=end

