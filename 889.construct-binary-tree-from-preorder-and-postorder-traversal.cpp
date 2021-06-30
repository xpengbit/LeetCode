/*
 * @lc app=leetcode id=889 lang=cpp
 *
 * [889] Construct Binary Tree from Preorder and Postorder Traversal
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
    vector<int> pre, post;
    int preIndex = 0;
    map<int, int> postMap;
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        this->pre = pre;
        this->post = post;
        for(int i = 0; i < pre.size(); i++) postMap[post[i]] = i;
        return constructFromPrePostHelper(0, pre.size() - 1);
    }
private:
    TreeNode* constructFromPrePostHelper(int postStart, int postEnd){
        if(postStart > postEnd) return nullptr;
        TreeNode* root = new TreeNode(pre[preIndex++]);
        if(postStart == postEnd) return root;
        int postIndex = postMap[pre[preIndex]];
        root->left = constructFromPrePostHelper(postStart, postIndex);
        root->right = constructFromPrePostHelper(postIndex + 1, postEnd - 1);
        return root;
    }
};
// @lc code=end

