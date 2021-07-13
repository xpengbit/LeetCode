/*
 * @lc app=leetcode id=1372 lang=cpp
 *
 * [1372] Longest ZigZag Path in a Binary Tree
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
    int maxLen = 0;
    int longestZigZag(TreeNode* root) {
        /*helper(root);
        return maxLen == 0 ? 0 : maxLen - 1;*/
        helper2(root, true);
        return maxLen;    
    }
private:
    int helper2(TreeNode* root, bool isLeft){
        if(!root) return 0;
        int l = helper2(root->left, true);
        int r = helper2(root->right, false);
        maxLen = max(maxLen, max(l, r));
        return isLeft ? r + 1 : l + 1;
    }
    vector<int> helper(TreeNode* root){
        if(!root) return vector<int>(2, 0);
        vector<int> res(2,0);  //res[0] 代表左子树的len， res[1] 代表右子树的len
        vector<int> l = helper(root->left);
        vector<int> r = helper(root->right);
        res[0] = l[1] + 1;   //左孩子的右子树+1
        res[1] = r[0] + 1;   //右孩子的左子树+1
        maxLen = max(maxLen, max(res[0], res[1]));
        return res;
    }
};
// @lc code=end

